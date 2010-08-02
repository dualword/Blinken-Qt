/***************************************************************************
 *   Copyright (C) 2005 by Albert Astals Cid <tsdgeos@terra.es>            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef COUNTER_H
#define COUNTER_H

class TQPainter;

class counter
{
	public:
		static void paint(TQPainter &p, bool drawScore, int score, bool drawTimer, const TQColor &c1, const TQColor &c2, const TQColor &c3);
		static int width(bool drawTimer);
		static int height();
};

#endif
