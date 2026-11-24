
#include <pl/Mod.hpp>

namespace {

class IsoCam {
public:
    static IsoCam& instance() {
        static IsoCam mod;
        return mod;
    }

    IsoCam() : mSelf(*ll::mod::NativeMod::current()) {}

    bool load() {
        mSelf.getLogger().info("IsoCam loaded safely");
        return true;
    }

    bool enable() {
        mSelf.getLogger().info("IsoCam enabled");
        return true;
    }

    bool disable() {
        mSelf.getLogger().info("IsoCam disabled");
        return true;
    }

    bool unload() {
        mSelf.getLogger().info("IsoCam unloaded");
        return true;
    }

private:
    ll::mod::NativeMod& mSelf;
};

}

PL_REGISTER_MOD(IsoCam, IsoCam::instance())
