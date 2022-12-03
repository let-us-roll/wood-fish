#include<windows.h>
#include<time.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)



int main() {
	initgraph(300, 600);
	setbkcolor(BLACK);
	cleardevice();
	IMAGE img;
	loadimage(&img, "woodfish.jpg", 300, 260);
	putimage(0, 300, &img);

	int n = 1;
	char str1[] = { "功德+1" };
	char str2[] = { "总功德：" };

	MOUSEMSG m;

	int time = 40;
	int r = 255 / time;
	
	for (;;)


	{

		if (KEY_DOWN(VK_LBUTTON)||KEY_DOWN(VK_RBUTTON))
		{
			PlaySound("knock.wav", NULL, SND_SYNC);
			settextcolor(WHITE);
			settextstyle(50, 0, "黑体");
			outtextxy(30, 0, str2);
			char num[20];
			sprintf(num, "%d", n);
			settextcolor(WHITE);
			settextstyle(50, 0, "仿宋");
			outtextxy(210, 0, num);

			BeginBatchDraw();
			for (int i = 0; i < time ; i++)
			{
				settextcolor(RGB(255-r*i,255-r*i,255-r*i));
				settextstyle(30, 0, "仿宋");
				outtextxy(100, 200-i, str1);
				FlushBatchDraw();
				Sleep(3);
			}
			EndBatchDraw();

			n++;
			
			
		}
	}
	closegraph;
	system("pause");

	return 0;
}