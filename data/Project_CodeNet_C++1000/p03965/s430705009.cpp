#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;
const ll LINF = 1LL<<58;
const ll mod = 1000000007;

int main(){
    string s;
    cin >> s;
    int g = 0, p = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p') p++;
        else g++;
    }
    cout << (g-p) / 2 << endl;
    return 0;
}