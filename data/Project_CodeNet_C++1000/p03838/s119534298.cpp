#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;

ll absll(ll a){
    if(a > 0) return a;
    else return -1*a;
}
int main() {

    ll x,y; cin >> x >> y;

    if(x == y) cout << 0;
    else if(x == 0 && y > 0) cout << y;
    else if(x == 0 && y < 0) cout << (abs(y)+1);
    else if(x > 0 && y == 0) cout <<x+1;
    else if(x < 0 && y == 0) cout << abs(x);
    else if((x > 0 && y > 0) && y > x) cout << absll(x-y);
    else if((x > 0 && y > 0) && y < x) cout << absll(x-y)+2;
    else if((x < 0 && y < 0) && x > y) cout << (absll(x-y)+2);
    else if((x < 0 && y < 0) && x < y) cout << (absll(x-y));
    else cout << (absll(x+y)+1);
    return 0;
}
