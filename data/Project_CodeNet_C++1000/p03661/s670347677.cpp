// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ull  unsigned long long
typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll INF = 1e15 + 5;
const int N = 2e5 + 123;
int main(){
    speed;
    int n;
    cin >> n;
    vi v(n + 1, 0);
    ll s = 0;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        s += v[i];
    }
    ll mn = INF;
    ll k = v[1];
    for(int i = 2; i <= n; ++i){
        ll x = abs(s - k - k);
        mn = min(mn, x);
        k += v[i];
    }
    cout << mn;
}