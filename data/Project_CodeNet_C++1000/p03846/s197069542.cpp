#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
    int n;cin>>n;
    const int INF = 1000000007;
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    
    if(n%2==1){
        int c=0;
        rep(i,n - 1){
            if(i%2==0 && a[i+1]!=a[i]+2 || i%2==1 && a[i+1]!=a[i])c=1;
        }
        if(a[0]!=0 || c==1){
            cout<<0<<endl;
            return 0;
        }
    }
    else{
        int c=0;
       rep(i,n - 1){
            if(i%2==1 && a[i+1]!=a[i]+2 || i%2==0 && a[i+1]!=a[i])c=1;
        }
        if(a[0]!=1 || c==1){
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=1;
    rep(i,n/2){
        ans*=2;
        ans%=INF;
    }
    cout<<ans<<endl;
	return 0;
}