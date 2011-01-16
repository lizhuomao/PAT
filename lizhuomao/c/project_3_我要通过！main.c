#include <stdio.h>
#include <stdlib.h>
/*项目3    ：我要通过！
  时间限制 ：400ms
  内存限制 ：655356kb
  代码长度 ：8000b
  作者	   ：李卓茂  
  日期	   ：2018.1.6	
*/
/*
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 
只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，
或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，
或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。
接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int num; //输入字符串的个数 
	printf("请输入要输入的字符串的个数");
	while (scanf_s("%d", &num) != 1 || num > 10)
	{
		printf("请输入一小于10的整数");
		while (getchar() != '\n')
			continue;
	}
	char str[num + 1][101]; //存储输入的字符 
	int judeg[num + 1]; //存储判断的对错 
	int i; //循环变量
	for (i = 0; i <= num; i++)
	{
		int j = 0; //递增变量 
		if (fgets(str[i], 100, stdin)) //循环读入字符串	
		{
			while (str[i][j] != '\0' &&str[i][j] != '\n')
				j++;
			if (str[i][j] == '\n')
				str[i][j] = '\0';
		}
	} 
	for (i = 1; i <= num; i++) //循环num次 
	{
	int sum, sum_A_a = 0, sum_A_b = 0, sum_A_c = 0; //计数变量：递增字符串， a区域的A字符个数初始化为0，b区域的A字符的个数， c区域的A字符的个数 		
		if (str[i][0] == 'P') //判断第一个字符是否为 P ， 如果为 P判断下一个字符是否为 A  如果不为 P判断是否为 A ，并记录 A的个数 记为sum_A_a 
		{
			if (str[i][1] == 'A') //判断第二个字符是否为 A, 如果为 A记录个数， 有 1个 A判断下一个字符是否为 T ，如果不为 1记录个数  记录 A的个数 记为 sum_A_b 
			{
				if (str[i][2] == 'T') //判断第三个字符是否为 T， 如过为 T判断下一个字符是否为 NULL 如果不为 T这里的 A的个数为 0个不为 0即为错 为 0为对 
				{
					if (str[i][3] == '\0') //第四个字符为 NULL的情况 ，判断位变为 1； 
					{
						judeg[i] = 1; 
						continue;
					}
					else //第四个字符不为 NULL的情况 ，判断位变为 0； 
					{
						judeg[i] = 0;
						continue;
					}

				}
				else if (str[i][3] == 'A') //第三个字符仍为 A的情况， 如果在遇到 T之前全为 A则进入下一阶段， 如有其他字符判断位置 0； 
				{
					sum = 3;
					while (str[i][sum] == 'A') //如果仍为 A的情况，直到遇到不为 A的字符 
					{
						++sum;
					}
					if (str[i][sum] == 'T') //如果为 T判断下一位是否为 NULL ，为 NULL则判断位置 1，不为 NULL则判断位置 0； 
					{
						if (str[i][sum + 1] == '\0') //为 NULL的情况 
						{
							judeg[i] = 1;
							continue;
						}
						else //不为 NULL的情况 
						{
							judeg[i] = 0;
							continue;	
						} 
					}
					else //不为 T与 A的情况 
					{
						judeg[i] = 0;
						continue;
					}
					
				}
				else //第三个字符即不为 A也不为 T的情况 
				{
					judeg[i] = 0;
					continue;
				}
			} 
			else //第二个字符不为 A的情况 
			{
				judeg[i] = 0;
				continue;
			}
		}
		else if (str[i][0] == 'A') //第一个字符为 A情况， 记录 A的个数，判断下一个字符为 A还是 P； 
		{
			sum = 0;
			while (str[i][sum] == 'A') //记录A的个数，记为sum_A_a; 
			{
				++sum;
				++sum_A_a;
			}
			if (str[i][sum] == 'P') //判断下一个字符是否为 P ， 如果为 P判断下一个字符是否为 P  如果不为 P判断是否为 A ，并记录 A的个数 记为sum_A_a 
			{
				if (str[i][sum + 1] == 'A') //判断第二个字符是否为 A, 如果为 A记录个数， 有 1个 A判断下一个字符是否为 T ，如果不为 1记录个数  记录 A的个数 记为 sum_A_b 
				{
					++sum_A_b;
					if (str[i][sum + 2] == 'T') //判断第三个字符是否为 T，
					{
						if (str[i][sum + 3] == 'A') //判断下一个字符是否为 A
						{
							++sum_A_c;
							while (str[i][sum + 4])
							{
								++sum;
								++sum_A_c;
							}
							if (sum_A_a == sum_A_c) //检查a处的字符串死否与b初的字符串相等 
							{
								judeg[i] = 1;
								continue;	
							} 
							else
							{
								judeg[i] = 0;
								continue;
							}
						}
						else 
						{
							judeg[i] = 0;	
							continue;
						} 

					}
					else if (str[i][sum + 2] == 'A') //第三个字符仍为 A的情况，  
					{
						++sum_A_b;
						while (str[i][sum + 3] == 'A') //如果仍为 A的情况，直到遇到不为 A的字符 并记录A的个数 
						{
							++sum_A_b;
							++sum;
						}
						if (str[i][sum + 3] == 'T') //如果为 T判断下一位是否为 NULL ，为 NULL则判断位置 1，不为 NULL则判断位置 0； 
						{
							if (str[i][sum + 4] == 'A')
							{
								++sum_A_c;
								while (str[i][sum + 5] == 'A')
								{
									++sum_A_c;
									++sum;
								}
								int sum_A_ab = sum_A_a + sum_A_b; 
								if (sum_A_c == sum_A_ab)
								{
									judeg[i] = 1;
									continue;
								}
								else
								{
									judeg[i] = 0;
									continue;
								}
							}
							else
							{
								judeg[i] = 0;
								continue;
							}
						}
						else //不为 T与 A的情况 
						{
							judeg[i] = 0;
							continue;
						}
						
					}
					else //第三个字符即不为 A也不为 T的情况 
					{
						judeg[i] = 0;
						
						continue;
					}
				} 
				else //第二个字符不为 A的情况 
				{
					judeg[i] = 0;
					continue;
				}
			}
		}
	}
	for (i = 1; i <= num; i++)
	{
		if(judeg[i] == 1)
		{
			puts("yes");
		}
		else 
		{
			puts("no");
		}
	}
	
	
	
	return 0;
}
