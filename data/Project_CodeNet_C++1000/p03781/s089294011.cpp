// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

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

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int MID = 1e5 + 3;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main(){
    speed;
    int n;
    cin >> n;
    for(int i = 1; i < MOD; ++i){
        if(i * (i + 1) / 2 >= n){
            cout << i;
            return 0;
        }
    }
}