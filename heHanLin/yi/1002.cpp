#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
1002. 写出这个数 (20)
https://www.patest.cn/contests/pat-b-practise/1002
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

int main() {
    unsigned long long n, sum=0, p, i;
    string s[10]; //0-9拼音数组
    stack<string> st;
    s[0] = "ling";
    s[1] = "yi";
    s[2] = "er";
    s[3] = "san";
    s[4] = "si";
    s[5] = "wu";
    s[6] = "liu";
    s[7] = "qi";
    s[8] = "ba";
    s[9] = "jiu";

    cin>>n;
    while(n!=0) {
        sum += n%10;
        n /= 10;
    }

    while(sum!=0) {
        p = sum%10;
        for(i=0; i<10; i++) {
            if(p==i) {
                st.push(s[i]);
                break;
            }
        }
        sum /= 10;
    }

    while(!st.empty()) {
        cout<<st.top();
        if(st.size()>1) {
            cout<<" ";
        }
        st.pop();
    }
    cout<<endl;
}