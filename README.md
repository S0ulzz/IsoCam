# IsoCam

Android native-mod starter scaffold for LeviLauncher / Preloader.

**Target requested:** Minecraft Bedrock 1.26.66, Android ARM64.

## Important status

This is a starter scaffold, **not a working camera or block-selection mod yet**.
The exact game hooks/signatures for Minecraft 1.26.66 have not been verified.
Do not install this as a finished `.levipack`.

## Planned features

- ISO camera toggle and camera settings in the LeviLauncher mod menu.
- Touch virtual cursor that does not steal the Minecraft movement joystick.
- Target-block highlight and interaction routed to the block under the cursor.
- Camera-relative movement while preserving normal jump/sprint behavior.

## Build

This repository is intended to be built with the official Android Preloader SDK and Android NDK.
The exact SDK package/API integration must be completed against the SDK version supported by the installed LeviLauncher release.

The workflow currently performs a source validation/package step only. It does not produce a functional native `.so` or `.levipack` until the SDK integration and game hooks are implemented.

## Safety / compatibility

Never use offsets copied from another Minecraft version. Re-check signatures against the exact game build.
