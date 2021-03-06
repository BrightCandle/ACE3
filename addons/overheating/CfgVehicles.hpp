class CfgVehicles {
    class Man;

    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class GVAR(UnJam) {
                    displayName = CSTRING(UnjamWeapon);
                    condition = QUOTE( GVAR(enabled) && {[_player] call FUNC(canUnjam)} );
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    statement = QUOTE( [ARR_2(_player, currentMuzzle _player)] call FUNC(clearJam); );
                    showDisabled = 0;
                    priority = 4;
                    icon = QPATHTOF(UI\unjam_ca.paa);
                };
                class GVAR(SwapBarrel) {
                    displayName = CSTRING(SwapBarrel);
                    condition = QUOTE( GVAR(enabled) && {'ACE_SpareBarrel' in magazines _player} && {getNumber (configFile >> 'CfgWeapons' >> currentWeapon _player >> 'ACE_Overheating_allowSwapBarrel') == 1} );
                    statement = QUOTE( [ARR_3(_player, _player, currentWeapon _player)] call FUNC(swapBarrel); );
                    showDisabled = 0;
                    priority = 3;
                    icon = QPATHTOF(UI\spare_barrel_ca.paa);
                };
                class GVAR(CheckTemperature) {
                    displayName = CSTRING(CheckTemperatureShort);
                    condition = QUOTE( GVAR(enabled) && {switch (currentWeapon _player) do {case (''): {false}; case (primaryWeapon _player); case (handgunWeapon _player): {true}; default {false}}} );
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    statement = QUOTE( [ARR_3(_player, _player, currentWeapon _player)] call FUNC(checkTemperature); );
                    showDisabled = 0;
                    priority = 2.9;
                    icon = QPATHTOF(UI\temp_ca.paa);
                };
                class GVAR(CheckTemperatureSpareBarrels) {
                    displayName = CSTRING(CheckTemperatureSpareBarrelsShort);
                    condition = QUOTE( GVAR(enabled) && {'ACE_SpareBarrel' in magazines _player});
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    statement = QUOTE( [_player] call FUNC(checkSpareBarrelsTemperatures); );
                    showDisabled = 0;
                    priority = 2.8;
                    icon = QUOTE(PATHTOF(UI\temp_ca.paa));
                };
            };
        };

        class ACE_Actions {
            class ACE_Weapon {
                class GVAR(SwapBarrel) {
                    displayName = CSTRING(SwapBarrel);
                    condition = QUOTE( GVAR(enabled) && {'ACE_SpareBarrel' in magazines _player} && {getNumber (configFile >> 'CfgWeapons' >> currentWeapon _target >> 'ACE_Overheating_allowSwapBarrel') == 1} );
                    statement = QUOTE([ARR_3(_player, _target, currentWeapon _target)] call FUNC(swapBarrelAssistant););
                    icon = QUOTE(PATHTOF(UI\spare_barrel_ca.paa));
                };
                class GVAR(CheckTemperature) {
                    displayName = CSTRING(CheckTemperatureShort);
                    condition = QUOTE( GVAR(enabled) && {switch (currentWeapon _target) do {case (''): {false}; case (primaryWeapon _target); case (handgunWeapon _target): {true}; default {false}}} );
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    statement = QUOTE( [ARR_3(_player, _target, currentWeapon _target)] call FUNC(checkTemperature); );
                    icon = QUOTE(PATHTOF(UI\temp_ca.paa));
                };
            };
        };
    };

    class ReammoBox_F;
    class NATO_Box_Base;
    class EAST_Box_Base;
    class IND_Box_Base;
    class FIA_Box_Base_F;

    class Box_NATO_Support_F: NATO_Box_Base {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class B_supplyCrate_F: ReammoBox_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class Box_East_Support_F: EAST_Box_Base {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class O_supplyCrate_F: B_supplyCrate_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class Box_IND_Support_F: IND_Box_Base {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class Box_FIA_Support_F: FIA_Box_Base_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class I_supplyCrate_F: B_supplyCrate_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class IG_supplyCrate_F: ReammoBox_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class C_supplyCrate_F: ReammoBox_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,2);
        };
    };

    class ACE_Box_Misc: Box_NATO_Support_F {
        class TransportItems {
            MACRO_ADDITEM(ACE_SpareBarrel,6);
        };
    };
};
