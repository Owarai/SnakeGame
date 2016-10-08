#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <vector>
#include <utility>
#include "ui_GameScreen.h"
#include <QTimer>
#include <time.h>

class GameScreen : public QWidget
{
	Q_OBJECT

public:
	static enum { MODE_MENU = 0, MODE_RUNNING, MODE_GAMEOVER };
	static enum { RANGE_DOWN = 0, RANGE_IDLE, RANGE_UP };

public:
	GameScreen(QWidget *parent = 0);
	~GameScreen();

	void keyPressEvent(QKeyEvent* pEvent);
	void keyReleaseEvent(QKeyEvent* pEvent);
	void init();

	public slots:
	void onTimer();

protected:
	void paintEvent(QPaintEvent * event);

private:
	Ui::GameScreen ui;

	int x_rand;
	int y_rand;

	int sq_s;
	int size_max;
	int prev_dir;
	int dir;

	int r;
	int g;
	int b;
	int r_dir;
	int g_dir;
	int b_dir;


	bool pause;

	int fruit;
	int coffee;

	int mode;

	std::vector<std::pair<int, int> > body;
	std::vector<std::pair<int, int> > fruit_loc;
	std::vector<std::pair<int, int> > coffee_loc;

	QTimer* timer;
	time_t lastTime;
	time_t respawn_last;
	time_t spam_last;

};

#endif // GAMESCREEN_H
