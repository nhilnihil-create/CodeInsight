#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include <string.h>
#define inf 0x7fffffff
using namespace std;
struct P
{
    int x,y;
    bool operator<(const P &a)const{
        if(y!=a.y)
        return y>a.y;
        return x>a.x;
    }
};
vector<int> v[200456];
int a,b,c,n,m,i,k,o[513][666],d,e,dy[5]={0,0,-1,1,0},dx[5]={0,1,1,1,2};
int l[300];
long long x,y,z[1111][33];
P u1[100100],u2[100100];
int j[200][10200];
priority_queue<P> q;
//long long x=0,y=0,z[99];

//deque<int> d;
//'1'==49;
map<int,int > p;
string r,r1;
//char r[1000];
bool asd(P a,P b)
{
   if(a.x-a.y!=b.x-b.y)
    return a.y-a.x<b.y-b.x;
   return a.x<b.x;
}



int main()
{
    scanf("%d %d %d",&a,&b,&c);
    for(int t=1;t<=a;t++)
        for(int w=1;w<=b;w++)
    {
        o[t][w]+=((t+w)/c%2);
    }
    for(int t=1;t<=a;t++)
        for(int w=1;w<=b;w++)
    {
        o[t][w]+=((1+(t-w+b)/c)%2*2);
    }

    for(int t=1;t<=a;t++,puts(""))
        for(int w=1;w<=b;w++)
    {
        if(o[t][w]==0) printf("R");
        if(o[t][w]==1) printf("Y");
        if(o[t][w]==2) printf("G");
        if(o[t][w]==3) printf("B");
    }
}
