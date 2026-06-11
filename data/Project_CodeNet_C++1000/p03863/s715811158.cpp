#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=0;
vector<ll> A;
string S;

signed main(){
    cin >> S;
    tmp = S.size()-2;
    if(S[0]==S.back()) tmp--;
    if(tmp%2) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}