#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793238462643383279
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int main(){
    int n,k;
    cin >> n >> k;

    vector<int>l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }

    sort(l.rbegin(),l.rend());

    int cnt = 0;
    for(int i = 0; i < k; i++){
        cnt += l[i];
    }

    cout << cnt << endl;





}