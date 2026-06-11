#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,cnt=0,sum=0;
    cin>>n;
    vector<int> s(n);
    rep(i,n) {
        cin>>s[i];
        sum+=s[i];
        if (s[i]%10==0) cnt++;
    }
    if (cnt==n) cout<<0<<endl;
    else if(sum%10!=0) cout<<sum<<endl;
    else {
        sort(s.begin(),s.end());
        rep(i,s.size()) {
            if (s[i]%10!=0) {
                sum-=s[i];
                cout<<sum<<endl;
                return 0;
            }
        }
    }
}
