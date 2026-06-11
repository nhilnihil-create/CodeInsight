#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A;
string S;

signed main(){
    cin >> S;
    A.resize(26,0);
    for(int i=0;i<S.size();i++) {
        ll abc = S[i]-'a';
        A[abc]++;
    }
    for(int i=0;i<26;i++) {
        ans += A[i]*(S.size()-A[i]);
    }
    ans /= 2;
    cout << ans+1 << endl;
    return 0;
}