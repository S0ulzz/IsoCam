
#include <atomic>
#include <cstdlib>
#include <string>
#include <string_view>

#include <pl/Mod.hpp>
#include <pl/ModMenu.hpp>

namespace {

constexpr const char* kModuleId = "isocam.camera";
constexpr const char* kEnabledKey = "camera_enabled";
constexpr const char* kAngleKey = "camera_angle";
constexpr const char* kDistanceKey = "camera_distance";

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
            pl::modmenu::ModuleBuilder(kModuleId, "IsoCam Camera")
                .modId(mSelf.getId())
                .description("Isometric camera settings")
                .defaultEnabled(true)
                .onToggle(onToggle)
                .config(
                    kEnabledKey,
                    "Camera Enabled",
                    pl::modmenu::ConfigType::Toggle,
                    "false"
                )
                .config(
                    kAngleKey,
                    "Camera Angle",
                    pl::modmenu::ConfigType::SliderFloat,
                    "45",
                    "15",
                    "75"
                )
                .config(
                    kDistanceKey,
                    "Camera Distance",
                    pl::modmenu::ConfigType::SliderFloat,
                    "10",
                    "3",
                    "30"
                )
                .onConfigChanged(onConfigChanged)
                .registerModule();

        if (registered) {
            mSelf.getLogger().info("IsoCam menu registered");
        } else {
            mSelf.getLogger().error("IsoCam menu registration failed");
        }

        return registered;
    }

    bool disable() {
        pl::modmenu::unregisterModule(kModuleId);
        mSelf.getLogger().info("IsoCam disabled");
        return true;
    }

    bool unload() {
        pl::modmenu::unregisterModule(kModuleId);
        mSelf.getLogger().info("IsoCam unloaded");
        return true;
    }

private:
    ll::mod::NativeMod& mSelf;

    std::atomic_bool mCameraEnabled{false};
    std::atomic<float> mCameraAngle{45.0f};
    std::atomic<float> mCameraDistance{10.0f};

    static void onToggle(std::string_view id, bool enabled) {
        if (id == kModuleId) {
            instance().mSelf.getLogger().info(
                "IsoCam module: {}",
                enabled ? "enabled" : "disabled"
            );
        }
    }

    static void onConfigChanged(
        std::string_view id,
        std::string_view key,
        std::string_view value
    ) {
        if (id != kModuleId) return;

        auto& mod = instance();

        if (key == kEnabledKey) {
            mod.mCameraEnabled =
                value == "true" || value == "1" || value == "on";
        } else if (key == kAngleKey) {
            mod.mCameraAngle = std::strtof(
                std::string(value).c_str(), nullptr
            );
        } else if (key == kDistanceKey) {
            mod.mCameraDistance = std::strtof(
                std::string(value).c_str(), nullptr
            );
        }

        mod.mSelf.getLogger().info(
            "IsoCam setting changed: {} = {}",
            key,
            value
        );
    }
};

}

PL_REGISTER_MOD(IsoCam, IsoCam::instance())
