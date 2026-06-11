#include <bits/stdc++.h>
#define MAXN 100010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e18 + 7;


int main (){
   int a, b, h;

   cin >> a >> b >> h;

   cout << ((a+b)*h)/2 << endl;
    return 0;
}