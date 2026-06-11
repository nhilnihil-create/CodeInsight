#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
ll gcd(int a, int b){return b ? gcd(b, a%b) : a;}
ll lcm(int a, int b){return a*b / gcd(a, b);}
const ll MAX = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<Pll> p(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }

    reverse(p.begin(), p.end());
    ll add = 0, ans = 0;
    for(auto x : p){
        ll rem = (x.first+add)%x.second;
        if(rem == 0) continue;

        ll shortage = x.second-rem;
        // cout << "short: " << shortage << "\n";
        ans += shortage;
        add += shortage;
    }

    cout << ans << endl;
    return 0;
}
