/***************************************************************************
 *   Copyright (C) 2008-2009 by Andrzej Rybczak                            *
 *   electricityispower@gmail.com                                          *
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
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef _SCREEN_H
#define _SCREEN_H

#include "window.h"

class BasicScreen
{
	public:
		BasicScreen() { }
		virtual ~BasicScreen() { }
		
		virtual void *&Cmp() = 0;
		
		virtual void Init() = 0;
		virtual void SwitchTo() = 0;
		virtual void Resize() = 0;
		
		virtual std::string Title() = 0;
		
		virtual void Update() { }
		virtual void Refresh() = 0;
		
		virtual void EnterPressed() { }
		virtual void SpacePressed() { }
};

template <class WindowType> class Screen : public BasicScreen
{
	public:
		Screen() : w(0) { }
		virtual ~Screen() { }
		
		virtual void *&Cmp();
		
		WindowType *&Main();
		
		virtual void Refresh();
		
	protected:
		WindowType *w;
};

template <class WindowType> void *&Screen<WindowType>::Cmp()
{
	return *(void **)(void *)&w;
}


template <class WindowType> WindowType *&Screen<WindowType>::Main()
{
	return w;
}

template <class WindowType> void Screen<WindowType>::Refresh()
{
	w->Display();
}

#endif

