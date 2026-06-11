#include <bits/stdc++.h>
#define MAXN 2010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e9 + 7;

ll n, m, ps[MAXN][MAXN];

int main (){
    ios_base::sync_with_stdio(false);
    int a, b, c;

    cin >> a >> b >> c;

    if (a+b == c || a+c == b || b+c == a){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}