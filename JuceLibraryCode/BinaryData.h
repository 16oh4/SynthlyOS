/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   midi_png;
    const int            midi_pngSize = 7646;

    extern const char*   waves_png;
    const int            waves_pngSize = 9712;

    extern const char*   tracks_png;
    const int            tracks_pngSize = 4581;

    extern const char*   sampler_png;
    const int            sampler_pngSize = 4857;

    extern const char*   pattern_png;
    const int            pattern_pngSize = 11099;

    extern const char*   effects_png;
    const int            effects_pngSize = 21889;

    extern const char*   mixer_png;
    const int            mixer_pngSize = 14088;

    extern const char*   play_button_png;
    const int            play_button_pngSize = 5108;

    extern const char*   battery_icon2_png;
    const int            battery_icon2_pngSize = 2702;

    extern const char*   cube_button2_png;
    const int            cube_button2_pngSize = 8337;

    extern const char*   pause_button_png;
    const int            pause_button_pngSize = 4688;

    extern const char*   back_button_png;
    const int            back_button_pngSize = 2633;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 12;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
