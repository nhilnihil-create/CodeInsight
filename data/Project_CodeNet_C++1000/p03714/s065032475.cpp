#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n*3];
    long long l[n+1]={},r[n+1]={};
    priority_queue<int>rq;
    priority_queue<int,vector<int>,greater<int>>lq;
    for(int i=0;i<n*3;i++){
        cin>>a[i];
        if(i<n){
            l[0]+=a[i];
            lq.push(a[i]);
        }
        if(i>=n*2){
            r[0]+=a[i];
            rq.push(a[i]);
        }
    }
    for(int i=n;i<n*2;i++){
        lq.push(a[i]);
        l[i-n+1]=l[i-n]+a[i]-lq.top();
        rq.push(a[3*n-i-1]);
        r[i-n+1]=r[i-n]+a[3*n-i-1]-rq.top();
        lq.pop(),rq.pop();
    }
    long long m=-1000000000000000000;
    //for(int i=0;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;
    for(int i=0;i<=n;i++)m=max(m,l[i]-r[n-i]);
    cout<<m<<endl;
    return 0;
}