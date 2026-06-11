#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <string>

#define loop(n) for(ll i=0;i<n;i++)

using namespace std;

typedef long long int ll;

int main() {
    ll b[100000],n,t,x = 0,y = 100000;
    memset(b,0,sizeof(ll[100000]));
    cin >> n;
    loop(n) {
        cin >> t;
        x = max(x,t);
        y = min(y,t);
        b[t]++;
    }
    
    if((x==y && (x+1 == n || x*2 <= n)) || (x==y+1 && b[y] + 1 <= x && x <= b[y] + b[x] / 2)) cout << "Yes" << endl;
    else cout << "No" << endl;
}