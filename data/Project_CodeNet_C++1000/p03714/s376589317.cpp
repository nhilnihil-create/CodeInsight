// 3N Numbers
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[300000],ans=-1e18,sumx[100009],sumy[100009];
signed main(){
    cin>>n;
    priority_queue<int> y;
    priority_queue<int,vector<int>,greater<int>> x;
    for(int i=0;i<3*n;i++){
        cin>>a[i];
        if(i<n)sumx[0]+=a[i],x.push(a[i]);
        if(2*n<=i)sumy[0]+=a[i],y.push(a[i]);
    }
    for(int i=0;i<n;i++){
        x.push(a[i+n]);
        sumx[i+1]=sumx[i]+a[i+n]-x.top();
        x.pop();
        y.push(a[2*n-i-1]);
        sumy[i+1]=sumy[i]+a[2*n-i-1]-y.top();
        y.pop();
    }
    for(int i=0;i<=n;i++)ans=max(sumx[i]-sumy[n-i],ans);
    cout<<ans<<endl;
}