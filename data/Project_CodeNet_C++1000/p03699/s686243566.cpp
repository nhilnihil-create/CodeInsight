#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int n;cin>>n;
    vector<int>s(n);
    int sum = 0;
    rep(i,n){cin>>s[i];sum+=s[i];}
    if(sum%10!=0){co(sum);return 0;}
    sort(s.begin(),s.end());
    rep(i,n){
        if((sum-s[i])%10!=0){co(sum-s[i]);return 0;}
    }
    co(0);
}