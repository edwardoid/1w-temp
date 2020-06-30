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

#ifndef W1_DEVICE_H
#define W1_DEVICE_H

#include <string>

namespace w1
{
    enum Precision
    {
        _9bits = 9,
        _10bits = 10,
        _11bits = 11,
        _12bits = 12
    };

    class Bus;
    class Device
    {
    public:
        Device() = delete;
        double temperature() const;
        void setPrecition(Precision precision);
        std::string address() const;
        std::string type() const;
    protected:
        friend Bus;
        Device(std::string path, std::string name);
    private:
        std::string w1_slave() const;
    private:
        std::string m_root;
        std::string m_name;
    };
}

#endif // W1_DEVICE_H