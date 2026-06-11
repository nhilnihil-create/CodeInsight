#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, a, b;
    cin >> x >> a >> b;
    int aa = abs(x - a);
    int bb = abs(x - b);
    //cout << aa << endl;
   // cout << bb << endl;
    if(aa < bb){
        cout << 'A' << endl;
    }
    else{
        cout << 'B' << endl;
    }
    return 0;
}
