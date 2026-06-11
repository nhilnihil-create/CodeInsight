#include<bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define vi vector
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LOCAL 0
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define pii pair<int,int>
#define f80 long double
 
#define int long long int
//typedef long long int ll;
 
const int mod = 1e9 + 7;
const int N = 200005;
 
main(){
    IO;
    if(LOCAL){
        freopen("inp.txt", "r", stdin);
    }
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    forn(i, 0, n - 1)
    {
        if(c * i + (n - 1 - i) * (-d) <= b - a && b - a <= d * i + (n - 1 - i) * (-c))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}