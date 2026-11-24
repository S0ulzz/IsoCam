
#include <pl/Mod.hpp>
#include <pl/ModMenu.hpp>

namespace {

constexpr const char* MODULE_ID = "isocam";

class IsoCam {
public:
    static IsoCam& instance() {
        static IsoCam mod;
        return mod;
    }

    IsoCam() : self(*ll::mod::NativeMod::current()) {}

    bool load() {
        self.getLogger().info("IsoCam loaded");
        return true;
    }

    bool enable() {
        const bool result =
            pl::modmenu::ModuleBuilder(MODULE_ID, "IsoCam")
                .modId(self.getId())
                .description("IsoCam native mod")
                .defaultEnabled(false)
                .registerModule();

        self.getLogger().info(
            result ? "IsoCam menu registered"
                   : "IsoCam menu registration failed"
        );

        return result;
    }

    bool disable() {
        pl::modmenu::unregisterModule(MODULE_ID);
        return true;
    }

    bool unload() {
        pl::modmenu::unregisterModule(MODULE_ID);
        return true;
    }

private:
    ll::mod::NativeMod& self;
};

}

PL_REGISTER_MOD(IsoCam, IsoCam::instance())
