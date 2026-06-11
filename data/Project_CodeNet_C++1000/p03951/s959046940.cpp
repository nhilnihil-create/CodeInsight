#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n; string s,t;
    cin>>n>>s>>t;
    if(s==t){cout<<n<<endl; return 0;}
    else{
        int ans=n;
        rep(i,n){
            if(s==t){
                break;
            }
            else{
                ans--;
                s=s.substr(1);
                t.pop_back();
            }
        }
        cout<<2*n-ans<<endl;
    }
}
