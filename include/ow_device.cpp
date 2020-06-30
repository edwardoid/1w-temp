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

#include "ow_device.h"
#include <fstream>
#include <iostream>
using namespace w1;

Device::Device(std::string path, std::string name)
    : m_root(path), m_name(name)
{}

double Device::temperature() const
{
    std::ifstream is(w1_slave());
    std::string line;
    while(std::getline(is, line)) {
        auto p = line.find(" t=");
        if (p < line.size()) {
            return ((double)(atoi(line.substr(p + 3).c_str()))) / 1000.;
        }
    }
    return 0;
}

void Device::setPrecition(Precision precision)
{
    std::ofstream os(w1_slave());
    os << (int)(precision);
}

std::string Device::address() const
{
    return m_name.substr(m_name.find_first_of('-') + 1);
}

std::string Device::type() const
{
    return m_name.substr(0, m_name.find_first_of('-'));
}

std::string Device::w1_slave() const
{
    std::string w1s = m_root;
    w1s += "/";
    w1s += m_name;
    w1s += "/w1_slave";
    return w1s;
}