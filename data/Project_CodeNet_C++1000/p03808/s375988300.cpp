#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define Ptest(x) return cout << x << endl, 0;

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, m, sum, p, d, k;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    m = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum % m){
        Ptest("NO");
    }
    k = sum / m;
    for (int i = 0; i < n; i++){
        d = a[(i + 1) % n] - a[i];
        if (k < d || (k - d) % n){
            Ptest("NO");
        }
        p += (k - d) / n;
    }
    if (k != p){
        Ptest("NO");
    }
    cout << "YES";
}

/*
----------------------------------+
INPUT:                            |
==============================    |
5
4 5 1 2 3
==============================    |
5
6 9 12 10 8
==============================    |
4
1 2 3 1
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
YES
==============================    |
YES
==============================    |
NO
==============================    |
----------------------------------+
*/