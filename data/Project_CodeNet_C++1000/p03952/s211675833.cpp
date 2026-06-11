#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;



int main()
{
    int n,x;
    cin >> n >> x;
    if (n==1 && x==1){
        cout << "Yes" << endl
             << 1 << endl;
        return 0;
    }
    if (x==1 || x==2*n-1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (x==n){
        rep(i,2*n-1){
            cout << i + 1 << endl;
        }
    }
    else if (x<n){
        repf(i,x+1,n+1){
            cout << i << endl;
        }
        repf(i,1,x+1){
            cout << i << endl;
        }
        repf(i,n+1,2*n){
            cout << i << endl;
        }
    }
    else{
        repf(i,1,n){
            cout << i << endl;
        }
        repf(i,x,2*n){
            cout << i << endl;
        }
        repf(i,n,x){
            cout << i << endl;
        }
    }
}
