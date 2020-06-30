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

#ifndef W1_BUS_H
#define W1_BUS_H

#include <vector>
#include "ow_device.h"

namespace w1
{
    struct Bus
    {
        static std::vector<Device> devices();
    };
}

#endif // W1_BUS_H