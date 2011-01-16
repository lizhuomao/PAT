#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
项目2    ；写出这个数
时间限制 ：400ms
内存限制 ：65536kb
代码长度 ：8000b
作者     ：李卓茂
时间     ：2018.1.3 
*/ 
/*项目要求 ： 
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。 
输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100。
输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
*/ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Choice_input(int number); //选择传入数对应的拼音输出 
struct stack //定义一个队列
{
	char data[101];
	int top; 	
};



int main(int argc, char *argv[]) 
{
	struct stack num; //存储输入的值 
	num.top = 0; //初始化栈 
	int i; //循环变量 
	int len; //存储字符长度 
	int all_bit_sum = 0; //存储各位和 
	int sum_in_bit; //存储和的其中一位 
	gets(num.data); //输入 
	len = strlen(num.data); //计算输入的长度 
	while (num.top < len)
	{
		all_bit_sum = all_bit_sum + num.data[num.top] - 48;
		num.top++;
	}
	if (all_bit_sum >= 1000)
	{
		sum_in_bit = (all_bit_sum % 10000) /1000;
		Choice_input(sum_in_bit);
		printf(" "); 
	}
	if (all_bit_sum >= 100) //判断和是否大于100 
	{
		sum_in_bit = (all_bit_sum % 1000) / 100;
		Choice_input(sum_in_bit);
		printf(" ");
	}
	if (all_bit_sum >=10)
	{
		sum_in_bit = (all_bit_sum % 100) / 10;
		Choice_input(sum_in_bit);
		printf(" ");
	}	
	if (all_bit_sum >= 0)
	{
		sum_in_bit = (all_bit_sum % 10) / 1;
		Choice_input(sum_in_bit);
	
	}
	
	
	/*

	unsigned int number[100]; //存储一个小于10^100的自然数
	
	
	int total_sum; //存储各位之和 
	printf("%d", sizeof(number));
	
	int sum; //存储输出的数 
	printf("请输入一个小于10100的自然数数：");
	while (scanf("%u", &number[100]) != 1) //输入调整及判断 
	{
		printf("请输入小于10100的自然数");
		while (getchar() != '\n')
			continue;
	}
	
	total_sum = number / 10000 + (number % 10000) / 1000 + (number % 1000) / 100 + (number % 100) / 10 + (number % 10) / 1; //计算各位之和 
	if (total_sum >= 100) //判断和是否大于100 
	{
		sum = total_sum / 100;
		Choice_input(sum);
		printf(" ");
	}
	if (total_sum >=10)
	{
		sum = (total_sum % 100) / 10;
		Choice_input(sum);
		printf(" ");
	}	
	if (total_sum >= 0)
	{
		sum = (total_sum % 10) / 1;
		Choice_input(sum);		
	}
*/	
	return 0;
}


void Choice_input(int number) //选择传入数对应的拼音输出 
{
	switch (number)
	{
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		case 10:
			printf("shi");
			break;
	}
	return;
}




