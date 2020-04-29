#include <bangtal.h>

SceneID title, scene1_0, scene1_1;
SceneID scene20, scene21, scene22, scene23, scene24;
SceneID scene30, scene31, scene32, scene33, scene34;
SceneID scene40;
SceneID ask;
SceneID run1;
SceneID ask1, ask2, ask2_2;

TimerID timer1;

ObjectID startbutton, endbutton, act1, key, Scene1, Scene1_1;
ObjectID Scene20, Scene21, Scene22, Scene23, Scene24;
ObjectID front1, front2, front3, front4, back1, back2, back3, back4, back5;
ObjectID front5, front6, front7, front8, front9;
ObjectID asker, asker2, Run1;
ObjectID door1,door2;
ObjectID ask1_1;
ObjectID wolf, wolf1, wolf2, wolf3, wolf4;
ObjectID ask2_3;
ObjectID door3;

bool closed1 = true;

ObjectID CreateObject(const char* image, SceneID scene, int x, int y) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	showObject(object);
	return object;
}
void makeback() {
	back1 = CreateObject("�ڷΰ���.png", scene20, 530, 10);
	back2 = CreateObject("�ڷΰ���.png", scene21, 530, 10);
	back3 = CreateObject("�ڷΰ���.png", scene22, 530, 10);
	back4 = CreateObject("�ڷΰ���.png", scene23, 530, 10);
	back5 = CreateObject("�ڷΰ���.png", scene24, 530, 10);
}
void hidefront1() {
	hideObject(front1);
	hideObject(front2);
	hideObject(front3);
	hideObject(front4);
}
void rest() {
	stopTimer(timer1);
	hideTimer();
	setTimer(timer1, 5.0f);
}
void run() {
	timer1 = createTimer(5.0f);
	showTimer(timer1);
	startTimer(timer1);
}
void StartGame() {
	hideObject(startbutton);
	hideObject(endbutton);
	enterScene(scene1_0);
}
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startbutton) {
		StartGame();
		showMessage("����... ���� �����?");
	}
	else if (object == endbutton) {
		endGame();
	}
	else if (object == Scene1) {
		if (x > 500 && x < 800 && y > 560 && y < 660) {
			hideObject(Scene1);
			showObject(act1);
		}
		else {
			showMessage("�� ���� ���캸��.");
		}
	}
	else if (object == act1) {
		enterScene(scene1_1);
		showMessage("��� ������..?");
	}
	else if (object == key) {
		pickObject(key);
	}
	else if (object == Scene1_1) {
		if (x > 500 && x < 800 && y > 500 && y < 660) {
			if (getHandObject() == key) {
				enterScene(scene20);
				showMessage("��, ���� ������ ���Դ�. ������ ������");
			}
			else {
				showMessage("���谡 ������ ���� �� ���� �� ����.");
			}
		}
	}
	else if (object == front1) {
		enterScene(scene21);
	}
	else if (object == front2) {
		enterScene(scene22);
	}
	else if (object == front3) {
		enterScene(scene23);
	}
	else if (object == front4) {
		enterScene(scene24);
		run();
		showMessage("��, ���� ����? ���� �������� ������ ū�ϳ� �� ����.");
		makeback();
	}
	else if (object == back1) {
		enterScene(run1);
		rest();
		showMessage("�Ͼ�.. �ܿ� �����Դ�. ���� ����� ?");
	}
	else if (object == back2) {
		enterScene(scene20);
	}
	else if (object == back3) {
		enterScene(scene21);
	}
	else if (object == back4) {
		enterScene(scene22);
		showMessage("��..?");
	}
	else if (object == back5) {
		enterScene(scene23);
		showMessage("�����....");
		hidefront1();
	}

	else if (object == front5) {
		enterScene(scene31);
		showMessage("��𼱰� ���� �����Ҹ��� ���� ..");
	}
	else if (object == front6) {
		enterScene(scene32);
	}
	else if (object == front7) {
		enterScene(scene33);
	}
	else if (object == front8) {
		showObject(wolf);
		enterScene(scene34);
		showMessage("�ٰ����� ������ �� ������ �������� �ʴ´�. Ŭ���غ���");
	}

	else if (object == Run1) {
		showMessage("��,, �ܿ� ���ƿԴ�. �׷��� ���� �ٸ���?");
		if (x > 500 && x < 800 && y > 560 && y < 660) {
			enterScene(ask);
			showMessage("����..?");
		}
		else {
			showMessage("���� ����� ã�ƺ���.");
		}
	}
	else if (object == asker) {
		showMessage("���� ������ Ǯ�� ���� ���� ���̴�. ���� ����� ������");
		enterScene(ask1);
	}
	else if (object == ask1_1) {
		showKeypad("20060518", door1);
	}
	else if (object == door1) {
		showMessage("������ Ǯ���");
	}
	else if (object == door2) {
		if (closed1 == false) {
			enterScene(scene30);
		}
	}
	else if (object == door3) {
	enterScene(scene40);
	showMessage("��.. ���Դ�. �� ������ ������..");
	}

	else if (object == wolf) {
		hideObject(wolf);
		showObject(wolf1);
	}
	else if (object == wolf1) {
		hideObject(wolf1);
		showObject(wolf2);
	}
	else if (object == wolf2) {
		hideObject(wolf2);
		showObject(wolf3);
	}
	else if (object == wolf3) {
		hideObject(wolf3);
		showObject(wolf4);
	}
	else if (object == wolf4) {
		hideObject(wolf4);
		showObject(front9);
		showMessage("���� ������ ���ư� �� �ִ�.");
	}
	else if (object == front9) {
		enterScene(ask2);
		showMessage("�� ��������.");
	}
	else if (object == asker2) {
		showMessage("������ Ǯ��߸� ������ ���ư� �� �ִ�.");
		enterScene(ask2_2);
	}
	else if (object == ask2_3) {
		showKeypad("324768", door3);
	}
}
void objectCallback(ObjectID object, EventID event) {
	if (object == door1) {
		if (event == EventID::EVENT_KEYPAD) {
			closed1 = false;
			hideObject(door1);
			showObject(door2);
			showMessage("�����̴�. ���� ���� ������. ���߿� �� ������ ����");
		}
	}
	else if (object == door3) {
		if (event == EventID::EVENT_KEYPAD) {
			showObject(door3);
			showMessage("�����̴�. ���� �������̴�.");
		}
	}
}
void timerCallback(TimerID timer) {
	if (timer == timer1) {
		enterScene(ask);
		rest();
		showMessage("����.. ���� �����?");
	}
}
int main() {
	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);
	setObjectCallback(objectCallback);

	ask = createScene("������ ��", "������.png");
	ask2 = createScene("������ ��", "������.png");

	ask1 = createScene("����1", "��.png");
	
	ask2_2 = createScene("����2", "��2.png");

	title = createScene("title", "���.png");
	scene1_0 = createScene("��ġ", "���۹��.png");
	scene1_1 = createScene("��ġ", "���۹��.png");
	run1 = createScene("����", "���۹��.png");
	scene20 = createScene("����", "����.png");
	scene21 = createScene("����", "����_1.png");
	scene22 = createScene("����", "����_2.png");
	scene23 = createScene("����", "����_3.png");
	scene24 = createScene("����", "����_4.png");

	scene30 = createScene("����", "����1.png");
	scene31 = createScene("����", "����1_1.png");
	scene32 = createScene("����", "����1_2.png");
	scene33 = createScene("����", "����1_3.png");
	scene34 = createScene("����", "����1_4.png");

	scene40 = createScene("����", "����2.png");
	

	startbutton = CreateObject("start.png", title, 590, 70);
	endbutton = CreateObject("end.png", title, 590, 20);
	Scene1 = CreateObject("���۹��.png", scene1_0, 0, 0);
	Scene1_1 = CreateObject("���۹��.png", scene1_1, 0, 0);
	key = CreateObject("����.png", scene1_1, 100, 90);
	Scene20 = CreateObject("����.png",scene20, 0, 0);
	Scene21 = CreateObject("����_1.png", scene21, 0, 0);
	Scene22 = CreateObject("����_2.png", scene22, 0, 0);
	Scene23 = CreateObject("����_3.png", scene23, 0, 0);
	Scene24 = CreateObject("����_4.png", scene24, 0, 0);

	front1 = CreateObject("�����ΰ���.png", scene20, 500, 70);
	front2 = CreateObject("�����ΰ���.png", scene21, 500, 70);
	front3 = CreateObject("�����ΰ���.png", scene22, 500, 70);
	front4 = CreateObject("�����ΰ���.png", scene23, 500, 70);


	front5 = CreateObject("�����ΰ���.png", scene30, 500, 70);
	front6 = CreateObject("�����ΰ���.png", scene31, 500, 70);
	front7 = CreateObject("�����ΰ���.png", scene32, 500, 70);
	front8 = CreateObject("�����ΰ���.png", scene33, 500, 70);
	front9 = createObject("�����ΰ���.png");
	locateObject(front9, scene34, 500, 70);

	Run1 = CreateObject("���۹��.png", run1, 0, 0);

	asker = CreateObject("������.png", ask, 0, 0);
	asker2 = CreateObject("������.png", ask2, 0, 0);

	ask1_1 = CreateObject("��.png", ask1, 0, 0);

	ask2_3 = CreateObject("��2.png", ask2_2, 0, 0);

	door1 = CreateObject("��1_1.png", ask1, 410, 0);
	door2 = createObject("��1_1.png");
	locateObject(door2, ask1, 410, 0);

	door3 = createObject("��2_2.png");
	locateObject(door3, ask2_2, 250, 140);

	wolf = createObject("����.jpg");
	locateObject(wolf, scene34, 570, 300);

	wolf1 = createObject("����1.jpg");
	locateObject(wolf1, scene34, 570, 310);

	wolf2 = createObject("����2.jpg");
	locateObject(wolf2, scene34, 570, 320);

	wolf3 = createObject("����3.jpg");
	locateObject(wolf3, scene34, 570, 330); 

	wolf4 = createObject("����4.jpg");
	locateObject(wolf4, scene34, 570, 340);
	
	scaleObject(key, 0.4f);
	
	act1 = createObject("���ȿ��.png");
	locateObject(act1, scene1_0, 0, 0);

	startGame(title);
}