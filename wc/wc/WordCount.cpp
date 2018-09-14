#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
#include<string.h>
int main(int argu,char *argv[])
{
	int wc_char=0;//字符数 
	int wc_word=1;//单词数 
	int wc_line=1;//行数 
	char filename[80];
	FILE *fp = NULL;
	void c_w_lCount(int wc_char,int wc_word,int wc_line,FILE *fp);
	void file_error(); 
	if (argu== 1){ 
	printf("请输入文件目录:\n");
		gets(filename);//获取文件 
		fp = fopen(filename, "r");
		if (fp == NULL)
		file_error(); 
		printf("文件打成功!文件内容如下:\n");
		c_w_lCount(wc_char,wc_word,wc_line,fp);
		fclose(fp);
		_getch();
		exit(0);
	}
}
void file_error(){ //文件打开错误函数 

	printf("打开有误！\n");
	printf("请按enter键继续....");
	_getch();
	exit(0);
}
void  c_w_lCount(int wc_char,int wc_word,int wc_line,FILE *fp){//单词，字符，行数计算函数 
	char *c;
	while (1){
		char ch;
		ch = fgetc(fp);//fgetc()：从FP中 返回一个字符 
		if (ch >= 'A'&&ch <= 'z')
	{
		putchar(ch);//终端输出一个字符 
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
	printf("\n该文件中字符数有 %d个。\n", wc_char);
	printf("该文件中单词数有 %d个。\n", wc_word);
	printf("该文件中行数有 %d行。\n", wc_line);
	printf("请输入统计方式如(-c\-w\-l):");//输入“-c"显示字符数 ,输入“-l"显示行数,输入“-w"显示单词数
		gets(c);
		if (strcmp(c, "-c") == 0)
		{
			printf("该文件中字符数有 %d个。\n",wc_char);
		}
		else if (strcmp(c, "-w") == 0)
		{
			printf("该文件中单词数有 %d个。\n",wc_word);
		}
		else if (strcmp(c, "-l") == 0)
		{
			printf("该文件中行数有 %d行。\n",wc_line);
		}
		exit(0);
}
