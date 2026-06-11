#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n,a,b;
vector<long long> h;

bool solve(long long num){
    vector<long long> v=h;
    for(int i=0;i<n;i++)v[i]-=num*b;
    long long cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]<=0)continue;
        cnt+=(v[i]+a-b-1)/(a-b);
    }
    return cnt<=num;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>a>>b;
    h.resize(n);
    for(int i=0;i<n;i++)cin>>h[i];
    long long l=0,r=INF;
    for(int i=0;i<100;i++){
        long long mid=(l+r)/2;
        if(solve(mid))r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}