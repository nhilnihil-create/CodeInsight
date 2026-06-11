#include<assert.h>　　　　//设定插入点
#include <ctype.h>                //字符处理　　　　
#include <errno.h>　　　　 //定义错误码
#include <float.h>　　　　 //浮点数处理
#include<limits.h>　　　　//定义各种数据类型最值常量
#include<locale.h>　　　　//定义本地化函数
#include <math.h>　　　　　//定义数学函数
#include <stdio.h>　　　　//定义输入／输出函数
#include<stdlib.h>　　　　//定义杂项函数及内存分配函数
#include <string.h>　　　　//字符串处理
#include<time.h>　　　　　//定义关于时间的函数
#include <wchar.h>　　　　//宽字符处理及输入／输出
#include <wctype.h>　　　　//宽字符分类
#include <algorithm>　　　 //STL通用算法
#include <bitset>　　　　　//STL位集容器
#include <cctype>                //字符处理
#include <cerrno>　　　　 //定义错误码
#include <clocale>　　　　//定义本地化函数
#include <cmath>　　　　　//定义数学函数
#include <complex>　　　　 //复数类
#include <cstdio>　　　　//定义输入／输出函数
#include <cstdlib>　　　　//定义杂项函数及内存分配函数
#include <cstring>　　　　//字符串处理
#include <ctime>　　　　　//定义关于时间的函数
#include <deque>　　　　　 //STL双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream>　　　//文件输入／输出
#include <functional>　　　//STL定义运算函数（代替运算符）
#include <limits>　　　　//定义各种数据类型最值常量
#include <list>　　　　　　//STL线性列表容器
#include <map>　　　　　　 //STL 映射容器
#include <iomanip>　　　//参数化输入／输出
#include <ios>　　　　　　//基本输入／输出支持
#include<iosfwd>　　　　　//输入／输出系统使用的前置声明
#include <iostream>　　　//数据流输入／输出
#include <istream>　　　　 //基本输入流
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 //STL队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　//基于字符串的流
#include <stack>　　　　　 //STL堆栈容器　　　　
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　//底层输入／输出支持
#include <string>　　　　　//字符串类
#include <utility>　　　　 //STL通用模板类
#include <vector>　　　　　//STL动态数组容器
#include <cwchar>　　　　//宽字符处理及输入／输出
#include <cwctype>　　　　//宽字符分类
#include <complex.h>　　//复数处理
#include <fenv.h>　　　　//浮点环境
#include <inttypes.h>　　//整数格式转换
#include <stdbool.h>　　 //布尔环境
#include <stdint.h>　　　//整型环境
#include <tgmath.h>　　　//通用类型数学宏
#define re register
#define ll long long
using namespace std;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
    ll x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
    }
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
string a,b;
int main() 
{
    getline(cin,a);
    b=a;
    reverse(a.begin(),a.end());
    for ( re int i=0;i<a.length();i++ ) 
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b) return printf("Yes\n"),0;
    else printf("No\n"),0;
    return 0;
}
        