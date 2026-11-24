// IsoCam native-mod entry point scaffold.
// TODO: Replace with the exact Preloader SDK headers and registration API
// after verifying the SDK version used by the target LeviLauncher release.
//
// No game hooks are installed here. This intentionally avoids unsafe,
// guessed offsets/signatures for Minecraft 1.26.66.

#include <cstdint>

namespace isocam {
    constexpr const char* kModName = "IsoCam";
    constexpr const char* kTargetMinecraft = "1.26.66";

    // Planned settings:
    // - camera_enabled
    // - camera_angle
    // - camera_distance
    // - cursor_enabled
    //
    // Planned input routing:
    // - preserve Minecraft movement joystick events
    // - consume touch only inside the virtual-cursor interaction region
    // - route target selection through a verified Minecraft block-raycast hook
}

