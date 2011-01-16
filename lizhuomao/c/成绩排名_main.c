#include <stdio.h>
#include <stdlib.h>

/*项目名称 ：成绩排名
  时间限制 ：400ms
  内存限制 ：65536kb
  代码长度 ：8000b
  作者	   ：李卓茂
  日期     ：2018.1.14 
*/ 

/*项目要求 ：
 读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩
 最低学生的姓名和学号。
输入格式：每个测试输入包含1个测试用例，格式为
  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
*/ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	char name[11];
	char number[11];
	int score;
}; //读入学生各种数据的结构体 
int main(int argc, char *argv[]) 
{
	unsigned int num; //读入的学生数
	printf("请输入要读入的学生数");
	while (scanf("%ud", &num) != 1) //输入测试 
	{
		puts("请输入一个正整数");
		while (getchar() != '\n')
			continue;
	} 
	struct student stu[num]; //创建一个学生类型 
	int i = 0, j = 0; //循环变量  
	for (i = 0; i < num; i++)
	{
		while (scanf("%s %s %d", &stu[i].name, &stu[i].number, &stu[i].score) != 3 || stu[i].score > 100 || stu[i].score < 0)
			{
				fflush(stdin);
				puts("您输入的格式有误！， 请重新输入。");
				while (getchar() != '\n')
					continue;
			}
//      scanf("%s %s %d", &stu[i].name, &stu[i].number, &stu[i].score);

	}
	for (i = 0; i < num - 1; i++) //对分数进行排序 
	{
		for (j = 0; j < num - 1 - i; j++) 
		{
			if (stu[j].score > stu[j + 1].score)
			{
				int temp = stu[j].score;
				stu[j].score = stu[j + 1].score;
				stu[j + 1].score = temp;
			}
		}
	}	
	printf("%s %s", stu[0].name ,stu[0].number);
	printf("\n%s %s", stu[num - 1].name, stu[num - 1].number);	
	return 0;
}
