#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll x,y;
    cin >> x >> y;
    if (x > 0 && y > 0 && x < y){
        cout << y - x << endl;
    }
    else if (x > 0 && y > 0 && x > y){
        cout << x - y + 2 <<  endl;
    }
    else if (x == 0 && y > 0){
        cout << y - x << endl;
    }
    else if (x < 0 && y == 0){
        cout << y - x << endl;
    }
    else if (x >= 0 && y <= 0){
        cout << abs(abs(x) - abs(y)) + 1 << endl;
    }
    else if (x <= 0 && y >= 0){
        cout << abs(abs(x) - abs(y)) + 1 << endl;
    }
    else if (x < 0 && y < 0 && x < y){
        cout << y - x << endl;
    }
    else if (x < 0 && y < 0 && x > y){
        cout << x - y + 2 << endl;
    }
}
