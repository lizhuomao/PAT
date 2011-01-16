#include <stdio.h>
#include <stdlib.h>
/*项目名称 ：继续（3n+1）猜想
  时间限制 ：400ms
  内存限制 ：65536kb
  代码长度 ：8000b
  作者     ：李卓茂
  日期     ：2018.1.16 
*/ 

/*代码要求 ： 
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。
例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，
就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，
我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。
你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。
输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
*/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct callatz{
	int data; //存储待验证的数 
	int data_2;//存储改变前的值 
	int record; //标记位 标记该数出现的次数 
};
int main(int argc, char *argv[]) 
{
	int num; //存储读入的待验证数的个数
	while (scanf("%d", &num) != 1 || num > 100 || num < 0) //读入次数 ，验证输入 
	{
		puts("请输入一个小于100的自然数");
		while (getchar() != '\n')
			continue;
	}
	struct callatz numbers[num]; //创建一个读入num个数的数组
	int i = 0, j = 0, x = 0; //循环变量 
	for (i = 0; i < num; i++) //标记位初始化 
		numbers[i].record = 0;
	int record_num[1000]; //存储（3n+1）过程中出现的数 
	for (i = 0; i < num; i++) //读入num个数， 并进行测试 
	{
		while (scanf("%d", &numbers[i].data) != 1 || numbers[i].data >100 || numbers[i].data <= 1)
		{
			puts("请输入一个大于1小于100的真整数");
			while (getchar() != '\n')
				continue;
		}	
	}
	for (i = 0; i < num; i++) //获取初始值 
	{
		numbers[i].data_2 = numbers[i].data;
	}
	for (i = 0; i < num; i++)  //（3n+1）猜想，记录出现过的数字 
	{
		while (numbers[i].data != 1)  
		{
			if (numbers[i].data % 2 == 1)
				numbers[i].data = (3 * numbers[i].data + 1) / 2;
			else
				numbers[i].data = numbers[i].data / 2;
			record_num[j] = numbers[i].data; //记录出现的数 
			++j;
		}
	}
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", record_num[i]);
//	}
	for (i = 0; i < num; i++)
	{
		x = 0; //初始化循环变量 
		while (x < j) //遍历记录数组 ，孤立关键数 
		{
			if (numbers[i].data_2 == record_num[x])
				numbers[i].record++;
			++x;
		}
	}
	int get[num]; //得到关键数 

	j = 0;
	for (i = 0; i < num; i++)
	{
		if(numbers[i].record == 0)
		{
			get[j] = numbers[i].data_2;			
			++j;
		}
	} 

		for (i = 0; i < j - 1; i++) //对关键字进行排序 
	{
		for (x = 0; x < j - i - 1; x++)
		{
			if (get[x] < get[x + 1])
			{
				int temp = get[x];
				get[x] = get[x + 1];
				get[x + 1] = temp;
			}
		}
	}

	for (i = 0; i < j; i++)
	{
		printf("%d ", get[i]);
	}
	return 0;
}




