#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
ll n;
deque<int>ans;
int cnt;
void solve(ll n)
{
    if(n==1) return;
    if(n&1)  solve(n-1),ans.push_front(++cnt);
    else     solve(n>>1),ans.push_back(++cnt);
}
int main()
{
    cin>>n;
    ++n;
    solve(n);
    printf("%d\n",cnt*2);
    for(int i=0;i<cnt;i++)  printf("%d ",ans[i]);
    for(int i=1;i<=cnt;i++)  printf("%d ",i);
    puts("");
    return 0;
}