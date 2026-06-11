#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,m,ans;
    cin>>n;
    long long t[n];
    f(i,0,n){
        cin>>t[i];
    }
    cin>>m;
    long long p[m],x[m];
    f(i,0,m){
        cin>>p[i]>>x[i];
    }
    f(i,0,m){
        ans=0;
        f(j,0,n){
            if(j+1==p[i]){
                ans+=x[i];
            }
            else{
                ans+=t[j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
