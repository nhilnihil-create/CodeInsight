#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
#define gc getchar()
#define hh putchar(10)
#define ll long long
#define mmin(a,b) (a>b?b:a)
template<class T>inline void qin(T &x){T f(1);char a;while((a=gc)<48)
(a==45)&&(f=-1);for(x=a^48;(a=gc)>47;x=(x<<3)+(x<<1)+(a^48));x*=f;}



void Main()
{
    int n,a;
    cin>>n>>a;
    cout<<(n*n-a);
}










int main(){Main();return 0;}