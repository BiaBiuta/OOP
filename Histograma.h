#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include "CosGUI.h"
class Histograma:public QWidget
{
private:
	ObiectService& cos;
public:
	Histograma(ObiectService& cos) :cos{ cos } {}
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		int x = 10;
		for (const auto& u : cos.get_cos()) {
			p.drawRect(x, 0, 20, 30);
			x += 20;
			/*p.drawImage(x, 0, QImage("sky.jpg"));*/
		}
	}
};

