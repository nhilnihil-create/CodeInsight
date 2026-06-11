#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
const int N=3e5+5;
int a[N];
typedef long long ll;
priority_queue<int,vector<int>,greater<int> >q;
priority_queue<int>Q;
ll pre[N];
int main(){
    int n;scanf("%d",&n);
    int m=3*n;
    for(int i=1;i<=m;i++) scanf("%d",a+i);
    ll sum=0;
    for(int i=1;i<=2*n;i++){
        q.push(a[i]);
        sum+=a[i];
        if(q.size()>n){
            sum-=q.top();
            q.pop();
        }
        if(i>=n) pre[i]=sum;
        pre[i]=max(pre[i],pre[i-1]);
    }
    ll ans=-1e18;
    sum=0;
    for(int i=m;i>n;i--){
        Q.push(a[i]);
        sum+=a[i];
        if(Q.size()>n){
            sum-=Q.top();
            Q.pop();
        }
        if(Q.size()==n){
            ans=max(ans,pre[i-1]-sum);
        }
    }
    printf("%lld",ans);
}
