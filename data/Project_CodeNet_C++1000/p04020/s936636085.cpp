#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
    int n;cin>>n;
    int a[n+1];
    ll ans=0,tmp;
    
    rep(i,n)cin>>a[i];
    a[n]=0;
    
    rep(i,n){
        tmp=a[i]/2;
        if(a[i]%2==1 && a[i+1]>0){
            tmp++;
            a[i+1]--;
        }
        ans+=tmp;
    }
    cout<<ans<<endl;
	return 0;
}