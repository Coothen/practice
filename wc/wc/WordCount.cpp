#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
#include<string.h>
int main(int argu,char *argv[])
{
	int wc_char=0;//�ַ��� 
	int wc_word=1;//������ 
	int wc_line=1;//���� 
	char filename[80];
	FILE *fp = NULL;
	void c_w_lCount(int wc_char,int wc_word,int wc_line,FILE *fp);
	void file_error(); 
	if (argu== 1){ 
	printf("�������ļ�Ŀ¼:\n");
		gets(filename);//��ȡ�ļ� 
		fp = fopen(filename, "r");
		if (fp == NULL)
		file_error(); 
		printf("�ļ���ɹ�!�ļ���������:\n");
		c_w_lCount(wc_char,wc_word,wc_line,fp);
		fclose(fp);
		_getch();
		exit(0);
	}
}
void file_error(){ //�ļ��򿪴����� 

	printf("������\n");
	printf("�밴enter������....");
	_getch();
	exit(0);
}
void  c_w_lCount(int wc_char,int wc_word,int wc_line,FILE *fp){//���ʣ��ַ����������㺯�� 
	char *c;
	while (1){
		char ch;
		ch = fgetc(fp);//fgetc()����FP�� ����һ���ַ� 
		if (ch >= 'A'&&ch <= 'z')
	{
		putchar(ch);//�ն����һ���ַ� 
		wc_char++;
	}
	else if (ch == ' ')
	{
	    putchar(ch);
		wc_word++;
	}
	else if (ch == '\n')
	{
		putchar(ch);
		wc_word++;
		wc_line++;
	}
	else if (ch==EOF)
	{
		break;
	}
}	_getch();
	printf("\n���ļ����ַ����� %d����\n", wc_char);
	printf("���ļ��е������� %d����\n", wc_word);
	printf("���ļ��������� %d�С�\n", wc_line);
	printf("������ͳ�Ʒ�ʽ��(-c\-w\-l):");//���롰-c"��ʾ�ַ��� ,���롰-l"��ʾ����,���롰-w"��ʾ������
		gets(c);
		if (strcmp(c, "-c") == 0)
		{
			printf("���ļ����ַ����� %d����\n",wc_char);
		}
		else if (strcmp(c, "-w") == 0)
		{
			printf("���ļ��е������� %d����\n",wc_word);
		}
		else if (strcmp(c, "-l") == 0)
		{
			printf("���ļ��������� %d�С�\n",wc_line);
		}
		exit(0);
}
