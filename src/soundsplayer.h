/* Blinken-Qt (2023) http://github.com/dualword/Blinken-Qt License:GNU GPL*/
/***************************************************************************
 *   Copyright (C) 2005 by Albert Astals Cid <aacid@kde.org>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef SOUNDSPLAYER_H
#define SOUNDSPLAYER_H

 #include <QAudioOutput>
 #include <QAudioDeviceInfo>
 #include <QtCore>

#include "blinkengame.h"
#include "settings.h"

class soundsPlayer : public QObject
{
Q_OBJECT
	public:
		soundsPlayer();
		~soundsPlayer();
		void play(blinkenGame::color c);
		
	Q_SIGNALS:
		void ended();
		
	private Q_SLOTS:
		void playEnded(QAudio::State);
		
	private:
		QString m_greenSound, m_redSound, m_blueSound, m_yellowSound, m_allSound;
		QTimer m_warnTimer;
	    QAudioFormat format;
	    QFile file;
	    QAudioOutput *out;
	    QBuffer data;
};

#endif
