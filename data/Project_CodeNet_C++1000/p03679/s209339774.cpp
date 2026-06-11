#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll x, a, b; cin >> x >> a >> b;

    if(b <= a) cout << "delicious" << endl;
    else if(b <= a+x) cout << "safe" << endl;
    else cout << "dangerous" << endl;
}

