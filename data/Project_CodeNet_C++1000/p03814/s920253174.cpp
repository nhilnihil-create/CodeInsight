#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    string s;
    cin >> s;

    int l=(int)s.size(),r=0;
    rep(i,(int)s.size()){
        if (s[i] == 'A') l = min(i, l);
        if (s[i] == 'Z') r = max(i, r);
    }
    cout(r - l + 1);

    return 0;
}