#include <Geode/Geode.hpp>
#include <Geode/loader/SettingV3.hpp>
#include <Geode/loader/Loader.hpp>

using namespace geode::prelude;

$execute {
    listenForSettingChanges("panorama", [](std::string value) {
        static const std::unordered_map<std::string, std::string> panoramaBaseMap = {
            { "The Garden Awakens", "thegardenawakens" },
            { "Tricky Trials", "trickytrials" },
            { "Trails & Tales", "trailsandtales" },
            { "The Wild Update", "thewild" },
            { "Caves & Cliffs: Part II", "cavesandcliffs2" },
            { "Caves & Cliffs: Part I", "cavesandcliffs1" },
            { "The Nether", "thenether" },
        };

        auto mod = Loader::get()->getLoadedMod("zalphalaneous.minecraft");
        if (mod && panoramaBaseMap.contains(value)) {
            std::string base = panoramaBaseMap.at(value);
            for (int i = 0; i < 6; ++i) {
                mod->setSavedValue("panorama-" + std::to_string(i), base + "_panorama_" + std::to_string(i) + ".png"_spr);
            }
            mod->setSavedValue("changed", true);
        }
    });
}
