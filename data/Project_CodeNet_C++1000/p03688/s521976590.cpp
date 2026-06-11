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
    ll b[100000],n,t,x,y;
    memset(b,0,sizeof(ll[100000]));
    cin >> n;
    x = 0;
    y = 100000;
    loop(n) {
        cin >> t;
        x = max(x,t);
        y = min(y,t);
        b[t]++;
    }
    if(x-y == 0) {
        if(x+1 == n || x*2 <= n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if(x-y == 1) {
        if(b[y] + 1 <= x && x <= b[y] + b[x] / 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}