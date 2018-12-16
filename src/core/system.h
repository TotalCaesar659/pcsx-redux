/***************************************************************************
 *   Copyright (C) 2018 PCSX-Redux authors                                 *
 *   Copyright (C) 2007 Ryan Schultz, PCSX-df Team, PCSX team              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.           *
 ***************************************************************************/

#pragma once

namespace PCSX {

class System {
  public:
    virtual void SysReset() = 0;                           // Request a system reset
    virtual void SysBiosPrintf(const char *fmt, ...) = 0;  // Printf used by bios syscalls
    virtual void SysBiosPrintf(const char *fmt, va_list va) = 0;
    virtual void SysPrintf(const char *fmt, ...) = 0;      // Printf used by the code in general
    virtual void SysMessage(const char *fmt, ...) = 0;     // Message used to print msg to users
    virtual void SysUpdate() = 0;                          // Called on VBlank (to update i.e. pads)
    virtual void SysRunGui() = 0;                          // Returns to the Gui
    virtual void SysClose() = 0;                           // Close mem and plugins
};

extern System *system;

}  // namespace PCSX
