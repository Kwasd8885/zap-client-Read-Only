#pragma once
#include "../Core/Level.hpp"
#include "../Core/LocalPlayer.hpp"
#include "../Core/Offsets.hpp"
#include "../Core/Player.hpp"
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XInput2.h>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

#include "../Math/QAngle.hpp"
#include "../Math/Resolver.hpp"
#include "../Math/Vector2D.hpp"
#include "../Math/Vector3D.hpp"

#include "../Utils/Config.hpp"
#include "../Utils/Conversion.hpp"
#include "../Utils/Features.hpp"
#include "../Utils/HitboxType.hpp"
#include "../Utils/InputManager.hpp"
#include "../Utils/InputTypes.hpp"
#include "../Utils/Memory.hpp"
#include "../Utils/Weapons.hpp"
#include "../Utils/XDisplay.hpp"
#include "../Utils/Kmbox_interface.hpp"

// UI //
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

typedef void* PVOID;

struct Misc {

  std::set<int> RapidFireList = {};

  float HangOnWall1;
  float HangOnWall2;
  float TraversalProgress1;
  float HangOnWall3;
  float HangOnWall4;
  float StartJumpTime1;

  XDisplay* X11Display;
  Level* Map;
  LocalPlayer* Myself;
  std::vector<Player*>* Players;

  Misc(XDisplay* X11Display, Level* Map, LocalPlayer* Myself,
       std::vector<Player*>* GamePlayers) {
    this->X11Display = X11Display;
    this->Map = Map;
    this->Myself = Myself;
    this->Players = GamePlayers;
  }

  static bool Save() {
    try {
      Config::Misc::SuperGlide = Features::Misc::SuperGlide;
      Config::Misc::SuperGlideMode = Features::Misc::SuperGlideMode;
      Config::Misc::SuperGlideFPS = Features::Misc::SuperGlideFPS;

      Config::Misc::QuickTurn = Features::Misc::QuickTurn;
      Config::Misc::QuickTurnAngle = Features::Misc::QuickTurnAngle;
      Config::Misc::QuickTurnBind =
        static_cast<int>(Features::Misc::QuickTurnBind);

      Config::Misc::BHop = Features::Misc::BHop;
      Config::Misc::BHopDelay = Features::Misc::BHopDelay;
      Config::Misc::BHopBind = static_cast<int>(Features::Misc::BHopBind);

      Config::Misc::RapidFire = Features::Misc::RapidFire;
      Config::Misc::RapidFireDelay = Features::Misc::RapidFireDelay;
      Config::Misc::RapidFireBind =
        static_cast<int>(Features::Misc::RapidFireBind);
    // Rapid Fire Weapons
      Config::Misc::RapidP2020 = Features::Misc::RapidP2020;
      Config::Misc::RapidR301 = Features::Misc::RapidR301;
      Config::Misc::RapidG7 = Features::Misc::RapidG7;
      Config::Misc::RapidFlatline = Features::Misc::RapidFlatline;
      Config::Misc::RapidHemlock = Features::Misc::RapidHemlock;
      Config::Misc::RapidProwler = Features::Misc::RapidProwler;
      Config::Misc::RapidNemesis = Features::Misc::RapidNemesis;
      Config::Misc::RapidMozambique = Features::Misc::RapidMozambique;
      Config::Misc::RapidEVA8 = Features::Misc::RapidEVA8;
      Config::Misc::RapidWingman = Features::Misc::RapidWingman;

      Config::Misc::SkinChanger = Features::Misc::SkinChanger;
      // Weapon IDs
      // Light
      Config::Misc::SkinP2020 = Features::Misc::SkinP2020;
      Config::Misc::SkinRE45 = Features::Misc::SkinRE45;
      Config::Misc::SkinALTERNATOR = Features::Misc::SkinALTERNATOR;
      Config::Misc::SkinR99 = Features::Misc::SkinR99;
      Config::Misc::SkinR301 = Features::Misc::SkinR301;
      Config::Misc::SkinSPITFIRE = Features::Misc::SkinSPITFIRE;
      Config::Misc::SkinG7 = Features::Misc::SkinG7;

      // Heavy
      Config::Misc::SkinFLATLINE = Features::Misc::SkinFLATLINE;
      Config::Misc::SkinHEMLOCK = Features::Misc::SkinHEMLOCK;
      Config::Misc::SkinREPEATER = Features::Misc::SkinREPEATER;
      Config::Misc::SkinRAMPAGE = Features::Misc::SkinRAMPAGE;
      Config::Misc::SkinCAR = Features::Misc::SkinCAR;

      // Energy
      Config::Misc::SkinHAVOC = Features::Misc::SkinHAVOC;
      Config::Misc::SkinDEVOTION = Features::Misc::SkinDEVOTION;
      Config::Misc::SkinLSTAR = Features::Misc::SkinLSTAR;
      Config::Misc::SkinTRIPLETAKE = Features::Misc::SkinTRIPLETAKE;
      Config::Misc::SkinVOLT = Features::Misc::SkinVOLT;
      Config::Misc::SkinNEMESIS = Features::Misc::SkinNEMESIS;

      // Shotgun
      Config::Misc::SkinMOZAMBIQUE = Features::Misc::SkinMOZAMBIQUE;
      Config::Misc::SkinEVA8 = Features::Misc::SkinEVA8;
      Config::Misc::SkinPEACEKEEPER = Features::Misc::SkinPEACEKEEPER;
      Config::Misc::SkinMASTIFF = Features::Misc::SkinMASTIFF;

      // Snipers
      Config::Misc::SkinLONGBOW = Features::Misc::SkinLONGBOW;
      Config::Misc::SkinCHARGE_RIFLE = Features::Misc::SkinCHARGE_RIFLE;
      Config::Misc::SkinSENTINEL = Features::Misc::SkinSENTINEL;

      // Legendary
      Config::Misc::SkinWINGMAN = Features::Misc::SkinWINGMAN;
      Config::Misc::SkinPROWLER = Features::Misc::SkinPROWLER;
      Config::Misc::SkinBOCEK = Features::Misc::SkinBOCEK;
      Config::Misc::SkinKRABER = Features::Misc::SkinKRABER;
      return true;
    } catch (...) {
      return false;
    }
  }

  void UpdateRapidFireList() {
    // Update RapidFireList
    RapidFireList.clear();
    if (Features::Misc::RapidP2020)
      RapidFireList.insert(WeaponIDs::WEAPON_P2020);
    if (Features::Misc::RapidR301)
      RapidFireList.insert(WeaponIDs::WEAPON_R301);
    if (Features::Misc::RapidG7)
      RapidFireList.insert(WeaponIDs::WEAPON_G7);
    if (Features::Misc::RapidFlatline)
      RapidFireList.insert(WeaponIDs::WEAPON_FLATLINE);
    if (Features::Misc::RapidHemlock)
      RapidFireList.insert(WeaponIDs::WEAPON_HEMLOCK);
    if (Features::Misc::RapidProwler)
      RapidFireList.insert(WeaponIDs::WEAPON_PROWLER);
    if (Features::Misc::RapidNemesis)
      RapidFireList.insert(WeaponIDs::WEAPON_NEMESIS);
    if (Features::Misc::RapidMozambique)
      RapidFireList.insert(WeaponIDs::WEAPON_MOZAMBIQUE);
    if (Features::Misc::RapidWingman)
      RapidFireList.insert(WeaponIDs::WEAPON_WINGMAN);
    if (Features::Misc::RapidEVA8)
      RapidFireList.insert(WeaponIDs::WEAPON_EVA8);
  }

  void Update() {
    // Skin changer was here
  } // End of update

  void SuperGlide() {
      // SuperGlide was here
    }

  void BHop() {
    // BHop was here
  }

  void QuickTurn() {
    // QuickTurn was here
  }

  void RapidFire() {
    if (!Myself->IsCombatReady())
      return;
    if (RapidFireList.find(Myself->WeaponIndex) == RapidFireList.end())
      return;
    if (InputManager::isKeyDownOrPress(Features::Misc::RapidFireBind)) {
      std::string command = "km.left(" + std::to_string(1)  + ")\r\n"; // left mouse button down
      Sleep(10); // to stop it from crashing idk
      std::string command1 = "km.left(" + std::to_string(0) + ")\r\n"; // left mouse button up
      send_command(hSerial, command.c_str());
      send_command(hSerial, command1.c_str());
      std::this_thread::sleep_for(
          std::chrono::milliseconds(Features::Misc::RapidFireDelay));
    }
  }
};
