/***************************************************************************
 *   Copyright (C) 2005 by Albert Astals Cid <tsdgeos@terra.es>            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef KSIMON_H
#define KSIMON_H

#include <qwidget.h>
#include <kxmlguiclient.h>

#include "simongame.h"

class QTimer;

class KAction;
class KHelpMenu;

class artsPlayer;
class highScoreDialog;

class KSimon : public QWidget, public KXMLGUIClient
{
Q_OBJECT
	public:
		KSimon();
		~KSimon();
		
	protected:
		void paintEvent(QPaintEvent *);
		void mouseMoveEvent(QMouseEvent *e);
		void mousePressEvent(QMouseEvent *e);
		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);
		
	private slots:
		void checkHS();
		void highlight(simonGame::color c, bool unhighlight);
		void unhighlight();
		
		void pressedYellow();
		void pressedRed();
		void pressedGreen();
		void pressedBlue();
		
	private:
		void drawMenuQuit(QPainter &p);
		void drawScoreAndCounter(QPainter &p);
		void drawStatusText(QPainter &p);
		void drawLevel(QPainter &p);
		void drawText(QPainter &p, const QString &text, const QPoint &center, bool withMargin, int xMargin, int yMargin, QRect *rect, bool highlight, bool bold);
		void updateButtonHighlighting(const QPoint &p);
		
		QPixmap *m_back, *m_blueh, *m_yellowh, *m_redh, *m_greenh, *m_highscore, *m_highscoreHover, *m_quit, *m_quitHover, *m_menu, *m_menuHover, *m_mark;
		bool m_overHighscore, m_overQuit, m_overCentralText, m_overMenu, m_overAboutKDE, 	m_overAboutKSimon, m_overManual, m_overLevels[3];
		// i obviously suck but m_levelsRect[0] is 2, m_levelsRect[1] is 1 and m_levelsRect[3] is ?
		QRect m_highscoreRect, m_quitRect, m_centralTextRect, m_menuRect, m_aboutKDERect, m_aboutKSimonRect, m_manualRect, m_levelsRect[3];
		QColor m_fillColor, m_fontColor, m_fontHighlightColor, m_countDownColor;
		
		// key setting handling
		bool m_showKeys;
		bool m_yellowClicked, m_redClicked, m_greenClicked, m_blueClicked;
		
		// if should update the highlighting after the next repaint
		bool m_updateButtonHighlighting;
		
		simonGame::color m_highlighted;
		QTimer *m_unhighlighter;
		
		QString m_lastName;
		
		artsPlayer *m_artsPlayer;
		simonGame m_game;
		
		KAction *m_yellowAction, *m_redAction, *m_greenAction, *m_blueAction;
		
		KHelpMenu *m_helpMenu;
};

#endif
