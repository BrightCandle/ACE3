#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_interaction"};
        author[] = {"commy2","KoffeinFlummi","esteldunedain"};
        authorUrl = "https://github.com/commy2/";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "CfgVehicles.hpp"
#include "CfgMagazines.hpp"
#include "CfgActions.hpp"
#include "CBA_Settings.hpp"
