#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void draw();
void end_event(int counter);

int event[6][7] = { 0 };
int flag1 = 1;

int main(void){
	int counter = 0;
	int x=0,y=0,pos=0;
	int cash = 0;
	int position[2];

	printf("** Sugoroku Games **\n\n");

	//コマンドの履歴を表示するかしないかの設定
	do{
		printf(" > コマの履歴を表示しますか？(true:1 , false:0):");
		scanf("%d", &cash);
		if (cash > 1 || cash <0){
			printf("  >> 数字は0または1のみで入力してください。\n\n");
		}
	} while (cash > 1 || cash <0);

	printf("\n > 初期化したフィールドを表示します...\n");

	do{
		//現在何度目のループかカウントし int counter に保存
		counter++;

		//サイコロの出た目の総計(pos)を表示する、posはdo-while文の最後尾周辺で行っている
		y = (pos - 1) / 7;
		if ((y % 2) == 0){
			x = pos - y * 7 - 1;
		}
		else{
			x = (y + 1) * 7 - pos;
		}
		//現在地をマーク
		event[y][x] = 1;

		//現在のステイタスを表示
		printf("\n\n＝＝ 現在 %d マス目 ＝＝\n", pos);
		printf(" Now Position : (%d.%d)\n",y,x);

		//描写する
		draw();

		//データを初期化する設定の場合のみ動く
		if (cash == 0){
			event[y][x] = 0;
		}

		//サイコロを振る前にポース(止まらない場合があるのでcharとintによる2重停止を試みています)
		char c;
		int n;
		printf("サイコロをふるために、何かキーを押してください... : ");
		scanf("%c", &c);
		scanf("%d", &n);

		//ランダムに数を生成
		int saikoro = 0;
		srand((unsigned)time(NULL));
		saikoro = rand() % 6 + 1;
		printf("\n > サイコロの数は%dでした。\n", saikoro);

		//サイコロの総数を記憶
		pos = pos + saikoro;

		//ゴールに達した場合に終了イベントを呼び出す
		if (pos >= 42){
			end_event(counter);
		}
		
	} while (flag1 != 0);
	return 0;
}

//描写関数
void draw(){
	int count = 0;
	int count2 = 0;
	//縦のデータ配列
	for (count = 0; count < 6; count++){
		//横のデータ配列
		printf("   ");
		for (count2 = 0; count2 < 7; count2++){
			//配列内が0であれば白丸を表示、そうでなければ黒丸を表示する
			if (event[count][count2] == 0){
				printf("○");
			}
			else{
				printf("●");
			}
		}
		printf("\n");
	}
}

//終了イベント
void end_event(int counter){
	//左下、ゴールを●にします
	event[5][0] = 1;

	//最後に結果を描写
	draw();

	//サイコロの回した回数を取得して表示

	//クレジットを表示
	printf("\n\n  ----------------------------------- \n");
	printf(" |    *   ***   G O A L   ***   *    |\n");
	printf(" |                                   |\n");
	//試行回数が9以下の場合に数字の前に0を挿入する
	if (counter > 9){
		printf(" | 試行回数 : %d                     |\n", counter);
	}
	else{
		printf(" | 試行回数 : 0%d                     |\n", counter);
	}
	printf(" |                                   |\n");
	printf(" | Copyright (C) 2015 Kohei Hasegawa |\n");
	printf(" | Released under the MIT license    |\n");
	printf(" | http://bit.ly/mit-l               |\n");
	printf("  ----------------------------------- \n\n");

	//フラッグを立ててmain関数のループを脱出
	flag1 = 0;
}