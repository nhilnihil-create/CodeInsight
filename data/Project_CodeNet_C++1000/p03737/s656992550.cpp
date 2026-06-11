#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    string a,b,c;
    cin>>a>>b>>c;
    string ans="";
    ans+=a[0]-'a'+'A';
    ans+=b[0]-'a'+'A';
    ans+=c[0]-'a'+'A';
    cout<<ans<<endl;
    return 0;
}