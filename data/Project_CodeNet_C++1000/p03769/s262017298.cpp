#include<bits/stdc++.h>
#define LL long long
using namespace std;
deque<int>q;
LL n;
int idx=0;
void dfs(LL x){
    if(!x)return;
    if(x&1){
        dfs((x-1)>>1);
        q.push_back(++idx);
    }
    else{
        dfs(x-1);
        q.push_front(++idx);
    }
}
int main()
{
    int i,j;
    cin>>n;
    dfs(n);
    deque<int>::iterator it;
    cout<<2*idx<<endl;
    for(it=q.begin();it<q.end();it++)cout<<*it<<" ";
    for(i=1;i<=idx;i++)cout<<i<<" ";
    cout<<endl;
    return 0;
}
