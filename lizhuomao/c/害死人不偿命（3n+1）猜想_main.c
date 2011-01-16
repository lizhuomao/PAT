#include <stdio.h>
#include <stdlib.h>
/*
项目1.	害死人不偿命的（3n+1）猜想 
时间限制 ：400ms
内存限制 ：65536kb
代码长度 ：8000b
作者     ：李卓茂 
时间     ：2018.1.3 
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*题目： 
卡拉兹(Callatz)猜想：
对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。
卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，
一心只证(3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展…… 
我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过1000的正整数n，简单地数一下，需要多少步（砍几下）才能得到n=1？ 
输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。
输出格式：输出从n计算到1需要的步数。*/


int main(int argc, char *argv[]) 
{
	int number; //存储输入的数 number <= 1000 
	int time = 0; //存储循环执行的次数,初始化为0 
	while (scanf_s("%d", &number) != 1 || number >1000) //输入调整，如果大于条件1000或非整数类型 
		{
			printf("请输入一个小于1000的整数\n");
			while (getchar() != '\n') 
				continue;	
		}	
	while (number != 1) //当number为1时跳出循环 
	{
			 if (number % 2 == 0) //判断number是否为偶数 
			 	number /= 2; //number的值砍掉一半 
			 else //是否为奇数 
			 	number = (3 * number + 1) / 2; //奇数变为他的（3n + 1） 
			time++; //累计次数 
	}
	printf("一共需要%d步number的值变为1", time);
	return 0;
}
