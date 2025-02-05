/* Blinken-Qt (2020) http://github.com/dualword/Blinken-Qt License:GNU GPL*/

#ifndef SRC_SETTINGS_H_
#define SRC_SETTINGS_H_

#include <QSettings>

class blinkenSettings {

public:

	blinkenSettings() = delete;

	static bool playSounds() {
		QSettings s;
		return s.value("playSounds", "1").toBool();
	}

	static bool customFont() {
		QSettings s;
		return s.value("customFont", "0").toBool();
	}

	static void setCustomFont(const bool& b) {
		QSettings s;
		s.setValue("customFont", b);
	}

	static void setPlaySounds(const bool& b) {
		QSettings s;
		s.setValue("playSounds", b);
	}

};



#endif /* SRC_SETTINGS_H_ */
