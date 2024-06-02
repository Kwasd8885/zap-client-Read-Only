# zap-client No memory write [Kmbox B+] (Unverified)

By **Gerosity**

All credits to original owners

Instructions are down below

# **Never cheat on a main account, its not worth it**

<details>
<summary><b>Features</b></summary>
    
    Legitbot - Aimbot, RCS, Visuals
    Triggerbot
    ESP - Enemy & Teammate, Spectator List, Crosshair, Radar
    Misc - Rapid Fire (For Semi-Auto & Burst Weapons)
    Settings - Disable Overlay, Disable ESP, FPS Cap
    Configs - Custom Configs, Premade Configs

</details>

<details>
<summary><b>Video Previews</b></summary>
    
**Menu Preview - Version 1.0.0:**

[![Menu](https://img.youtube.com/vi/VBnAyOhTSIs/0.jpg)](https://www.youtube.com/watch?v=VBnAyOhTSIs)

**Release - Version 1.0.0:**

[![Release - Version 1.0.0](https://img.youtube.com/vi/vCsmewJlgk0/0.jpg)](https://www.youtube.com/watch?v=vCsmewJlgk0)

**Update - Version 1.1.0:**

[![Update - Version 1.1.0](https://img.youtube.com/vi/YyiQNBgrV1Q/0.jpg)](https://www.youtube.com/watch?v=YyiQNBgrV1Q)
</details>

# Other Repositories:
https://github.com/Gerosity/zap-client-Read-Only-   - A read memory only version

https://github.com/Gerosity/Apex-Protection         - A protection guide, not fully tested but its not like its going to hurt using it

# Before Installation
**Install Linux**

    Not hard at all, use Google & YouTube. Search "How to dual boot Linux and windows"
    NOTE: It is recommened to use GNOME or Cinnamon as your desktop environment. KDE Plasma is known not to allow the overlay to be drawn above the game.
    Other desktop environments may work

**Install Steam & Apex**
  
    Use YouTube & Google for this.
    if upon opening apex you get a black screen and it does not open, follow this: https://www.unknowncheats.me/forum/4012140-post13.html

# Installation
**1 Install dependencies**
<details>
<summary><b>Debian dependencies</b></summary>
    
    sudo apt-get install -y libudev-dev
    sudo apt install cmake xorg-dev libglu1-mesa-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
    sudo apt install -y libudev-dev libglu1-mesa-dev libxkbcommon-dev libwayland-dev git cmake g++ gcc libinput-dev libsoil-dev
    sudo apt-get install build-essential
    sudo apt-get install libx11-dev
    sudo apt-get install libxtst-dev

</details>
<details>
<summary><b>Arch dependencies - Look through the UC thread for any more information</b></summary>
    
    sudo pacman -Sy libudev0 cmake xorg-server git base-devel libx11 libxtst

</details>

**2.Build glfw**

    git clone https://github.com/glfw/glfw.git
    cd glfw
    mkdir build
    cd build
    cmake ..
    make
    sudo make install

**3. Exit the terminal and re-open it (So that you dont build the cheat directly into the GLFW build folder, wont work otherwise)**

**4. Clone repo**

    git clone https://github.com/Gerosity/zap-client.git
    cd zap-client

**5. Build & Run**

    mkdir build
    cd build
    cmake ..
    make
    chmod +x run.sh

    Then Either:
    sudo ./zapclient
    or
    ./run.sh

**6. Press Insert to toggle the Menu (You can only interact with the Menu and the game when the menu is active).**
**Note: You will need to alt+tab between the cheat overlay and apex.**

# Credits:
    https://github.com/sys-1337/kmbox-communication - kmbox code to control the mouse
    https://github.com/Nexilist/xap-client - for the base, massive credits to them
    https://github.com/arturzxc/grinder - alternate aimbot mode, most of the misc features
    https://github.com/Braziliana/T_TApe - custom config system
    https://www.unknowncheats.me/forum/apex-legends/ - A TON of help, offsets, many additional features & more
    wafflesgaming - aimbot help, Extra ESP Features such as 2D Corners
    0xAgartha & ghostrazzor - run.sh script (Randomises zapclient binary & Hides PID before execution)
    hir0xy - Version Checker, Overlay Fixes, Cleaner GUI & optimizations here and there

