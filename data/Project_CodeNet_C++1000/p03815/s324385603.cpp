#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    long long x;
    cin>>x;
    //6,5,6,5,6と得点するのが最良
    long long ans=0;
    ans+=(x/11)*2;
    if(x%11>0){
        if(x%11>6) ans+=2;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}