/*
* 1w-temp - 1-Wide device temperature reader
* Copyright (C) 2019  Eduard Sargsyan
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ow_bus.h"

#include <iostream>
#include <string>
#include <dirent.h>

using namespace w1;

#ifndef W1_BUS_ROOT
#define W1_BUS_ROOT "/sys/bus/w1/devices"
#endif // W1_BUS_ROOT

std::vector<Device> Bus::devices()
{
    DIR* bus = opendir(W1_BUS_ROOT);

    std::vector<Device> devices;
    if (bus == NULL) {
        closedir(bus);
        return devices;
    }

    dirent* child = NULL;
    while(NULL != (child = readdir(bus))) {
        std::string name = child->d_name;
        if (/*child->d_type != DT_LNK || */name == "." || name == "..") {
            continue;
        }


        std::string w1Class = name.substr(0, name.find_first_of('-'));

        if (w1Class == "10" || w1Class == "22" || 
            w1Class == "28" || w1Class == "3B" || 
            w1Class == "42" ) {
            devices.emplace_back(Device(W1_BUS_ROOT, name));
        }
    }

    closedir(bus);
    return devices;
} 