#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#define INF 0x3f3f3f3f
int read()
{
    int x=0,f=1;    char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}
//priority_queue<int,vector<int>,greater<int> >q1;
priority_queue<int,vector<int>,less<int> >q;
//priority_queue<int,vector<int>,less<int> >q2;
const ll maxn = 1e6 + 7;
const int mod = 1e9 + 7;
/** keep hungry and keep calm! **/

/**
奇数+奇数 = 偶数
偶数+偶数 = 偶数
不管有多少偶数一定能相加
只有奇数有奇数个时会单出来一个 
**/
int main()
{
    int n,tmp;
    bool book = true;
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
	{
        scanf("%d",&tmp);
        if(tmp %2 != 0)
		{
            book=!book;
        }
    }
    if(book){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}