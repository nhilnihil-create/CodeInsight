#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;cin>>n;
    int s[n];
    rep(i,n)cin>>s[i];
    sort(s,s+n);
    int ans = 0;
    rep(i,n)ans+=s[i];
    if(ans%10 !=0){
        cout<<ans<<endl;
        return 0;
    }
    else{
        rep(i,n)if(s[i]%10 !=0){
            ans-=s[i];
            cout<<ans<<endl;
            return 0;
        }
    }
  cout<<0<<endl;
	return 0;
}

