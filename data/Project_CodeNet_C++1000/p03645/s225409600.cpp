#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
int main() {
	speed;
    int n, m; cin >> n >> m;
    map<int, bool> m1;
    map<int, bool> m2;
    vector<pii> v(m);
    bool yes = false;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        if(l == 1) {
            m1[r] = true;
        }
        if(r == n) {
            m2[l] = true;
        }
    }
    It(m1) {
        if(m2[it->first] == true) {
            yes = true;
        }
    }
    if(yes) {
        cout << "POSSIBLE";
    }
    else {
        cout << "IMPOSSIBLE";
    }
}
