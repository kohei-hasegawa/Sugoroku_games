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

	//�R�}���h�̗�����\�����邩���Ȃ����̐ݒ�
	do{
		printf(" > �R�}�̗�����\�����܂����H(true:1 , false:0):");
		scanf("%d", &cash);
		if (cash > 1 || cash <0){
			printf("  >> ������0�܂���1�݂̂œ��͂��Ă��������B\n\n");
		}
	} while (cash > 1 || cash <0);

	printf("\n > �����������t�B�[���h��\�����܂�...\n");

	do{
		//���݉��x�ڂ̃��[�v���J�E���g�� int counter �ɕۑ�
		counter++;

		//�T�C�R���̏o���ڂ̑��v(pos)��\������Apos��do-while���̍Ō�����ӂōs���Ă���
		y = (pos - 1) / 7;
		if ((y % 2) == 0){
			x = pos - y * 7 - 1;
		}
		else{
			x = (y + 1) * 7 - pos;
		}
		//���ݒn���}�[�N
		event[y][x] = 1;

		//���݂̃X�e�C�^�X��\��
		printf("\n\n���� ���� %d �}�X�� ����\n", pos);
		printf(" Now Position : (%d.%d)\n",y,x);

		//�`�ʂ���
		draw();

		//�f�[�^������������ݒ�̏ꍇ�̂ݓ���
		if (cash == 0){
			event[y][x] = 0;
		}

		//�T�C�R����U��O�Ƀ|�[�X(�~�܂�Ȃ��ꍇ������̂�char��int�ɂ��2�d��~�����݂Ă��܂�)
		char c;
		int n;
		printf("�T�C�R�����ӂ邽�߂ɁA�����L�[�������Ă�������... : ");
		scanf("%c", &c);
		scanf("%d", &n);

		//�����_���ɐ��𐶐�
		int saikoro = 0;
		srand((unsigned)time(NULL));
		saikoro = rand() % 6 + 1;
		printf("\n > �T�C�R���̐���%d�ł����B\n", saikoro);

		//�T�C�R���̑������L��
		pos = pos + saikoro;

		//�S�[���ɒB�����ꍇ�ɏI���C�x���g���Ăяo��
		if (pos >= 42){
			end_event(counter);
		}
		
	} while (flag1 != 0);
	return 0;
}

//�`�ʊ֐�
void draw(){
	int count = 0;
	int count2 = 0;
	//�c�̃f�[�^�z��
	for (count = 0; count < 6; count++){
		//���̃f�[�^�z��
		printf("   ");
		for (count2 = 0; count2 < 7; count2++){
			//�z�����0�ł���Δ��ۂ�\���A�����łȂ���΍��ۂ�\������
			if (event[count][count2] == 0){
				printf("��");
			}
			else{
				printf("��");
			}
		}
		printf("\n");
	}
}

//�I���C�x���g
void end_event(int counter){
	//�����A�S�[�������ɂ��܂�
	event[5][0] = 1;

	//�Ō�Ɍ��ʂ�`��
	draw();

	//�T�C�R���̉񂵂��񐔂��擾���ĕ\��

	//�N���W�b�g��\��
	printf("\n\n  ----------------------------------- \n");
	printf(" |    *   ***   G O A L   ***   *    |\n");
	printf(" |                                   |\n");
	//���s�񐔂�9�ȉ��̏ꍇ�ɐ����̑O��0��}������
	if (counter > 9){
		printf(" | ���s�� : %d                     |\n", counter);
	}
	else{
		printf(" | ���s�� : 0%d                     |\n", counter);
	}
	printf(" |                                   |\n");
	printf(" | Copyright (C) 2015 Kohei Hasegawa |\n");
	printf(" | Released under the MIT license    |\n");
	printf(" | http://bit.ly/mit-l               |\n");
	printf("  ----------------------------------- \n\n");

	//�t���b�O�𗧂Ă�main�֐��̃��[�v��E�o
	flag1 = 0;
}