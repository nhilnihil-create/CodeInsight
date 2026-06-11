#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n;
    int t[n+1],sum=0;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    cin>>m;
    int p[m],x[m];
    for(int i=0;i<m;i++){
        int sum1=sum;
        cin>>p[i]>>x[i];
        sum1=sum1-t[p[i]]+x[i];
        cout<<sum1<<endl;
    }
}