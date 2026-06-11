#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define N 100005
#define rep(i,a,n) for(int i=a;i<n;++i)
#define pb push_back
#define mp make_pair
#define LL long long
#define fi first
#define se second

set<int>f;
void fun(int n){
    int i,s,m=sqrt(2*n);
    while(m*(m+1)<n*2)
        ++m;
    while(m*(m+1)>2*n)
        --m;
    ++m;
    s=(m+1)*m/2;
    s-=n;
    for(i=1;i<=m;++i){
        if(i==s) continue;
        cout<<i<<' ';
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    fun(n);
    return 0;
}
