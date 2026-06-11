#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    ll a , b , x;
    cin >> a >> b >> x;
    if(a % x == 0){
        cout << b / x - a / x + 1 << endl;;
    }
    else{
        cout << b / x - a / x << endl;;
    }
}
