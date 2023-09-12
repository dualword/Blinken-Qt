/* Blinken-Qt (2023) http://github.com/dualword/Blinken-Qt License:GNU GPL*/
/***************************************************************************
 *   Copyright (C) 2005 by Albert Astals Cid <aacid@kde.org>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "soundsplayer.h"

soundsPlayer::soundsPlayer()
{
	format.setSampleRate(44100);
	format.setChannelCount(1);
	format.setSampleSize(16);
	format.setCodec("audio/pcm");
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::SignedInt);
	out = new QAudioOutput(format, this);
	connect(out, SIGNAL(stateChanged(QAudio::State)), SLOT(playEnded(QAudio::State)));

	m_allSound = ":/lose.wav";
	m_greenSound = ":/1.wav";
	m_redSound = ":/2.wav";
	m_blueSound = ":/3.wav";
	m_yellowSound = ":/4.wav";

	connect(&m_warnTimer, &QTimer::timeout, this, &soundsPlayer::ended);
	m_warnTimer.setSingleShot(true);
}

soundsPlayer::~soundsPlayer()
{
	if(out) delete out;
}

void soundsPlayer::play(blinkenGame::color c)
{
	if (blinkenSettings::playSounds())
	{
		QString soundFile;
		switch (c)
		{
			case blinkenGame::red:
				soundFile = m_redSound;
			break;

			case blinkenGame::green:
				soundFile = m_greenSound;
			break;

			case blinkenGame::blue:
				soundFile = m_blueSound;
			break;

			case blinkenGame::yellow:
				soundFile = m_yellowSound;
			break;

			case blinkenGame::all:
				soundFile = m_allSound;
			break;

			default:
			break;
		}
		if (!soundFile.isEmpty())
		{
			file.setFileName(soundFile);
			file.open(QIODevice::ReadOnly);
			data.setData(file.readAll());
			data.open(QIODevice::ReadOnly);
			file.close();
			out->setBufferSize(data.size());
			data.seek(0);
			out->start(&data);
		}
	}
	else
	{
		m_warnTimer.start(250);
	}
}

void soundsPlayer::playEnded(QAudio::State state)
{
	switch (state) {
		case QAudio::IdleState:
			if (blinkenSettings::playSounds())
			{
				m_warnTimer.start(250);
			}
			out->stop();
			data.close();
		  break;
	}
}
