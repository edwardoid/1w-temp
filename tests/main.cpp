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

#include "bus.h"

#include <iostream>
int main()
{
    for(auto d : w1::Bus::devices())
    {
        std::cout << "Addr: " << d.address() << " type: " << d.type() << "\n";
        d.setPrecition(w1::Precision::_9bits);
        std::cout << "\tResolution: 9\t" << d.temperature() << "\n";

        d.setPrecition(w1::Precision::_10bits);
        std::cout << "\tResolution: 10\t" << d.temperature() << "\n";

        d.setPrecition(w1::Precision::_11bits);
        std::cout << "\tResolution: 11\t" << d.temperature() << "\n";
        
	    d.setPrecition(w1::Precision::_12bits);
        std::cout << "\tResolution: 12\t" << d.temperature() << "\n";
    }
    return 0;
}
