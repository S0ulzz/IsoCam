
#include <pl/Mod.hpp>
#include <pl/ModMenu.hpp>

namespace {

constexpr const char* kModuleId = "isocam.camera";

class IsoCam {
public:
    static IsoCam& instance() {
        static IsoCam mod;
        return mod;
    }

    IsoCam() : mSelf(*ll::mod::NativeMod::current()) {}

    bool load() {
        mSelf.getLogger().info("IsoCam loaded");
        return true;
    }

    bool enable() {
        const bool registered =
            pl::modmenu::ModuleBuilder(
                kModuleId,
                "IsoCam Camera"
            )
            .modId(mSelf.getId())
            .description("Isometric camera settings")
            .defaultEnabled(true)
            .registerModule();

        if (registered) {
            mSelf.getLogger().info("IsoCam module registered");
        } else {
            mSelf.getLogger().error("IsoCam module registration failed");
        }

        return registered;
    }

    bool disable() {
        pl::modmenu::unregisterModule(kModuleId);
        return true;
    }

    bool unload() {
        pl::modmenu::unregisterModule(kModuleId);
        return true;
    }

private:
    ll::mod::NativeMod& mSelf;
};

}

PL_REGISTER_MOD(IsoCam, IsoCam::instance())
