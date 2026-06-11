#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;cin>>s;
    int n = s.size();
    int ans=2;
  
    for(int i=2;i<=n/2;i+=2){
        int m = n - i;
        int cc = 0;
        rep(j,m/2){
            if(s[j]!=s[m/2 + j])cc=1;
        }
        if(cc == 0){
            ans = m;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}