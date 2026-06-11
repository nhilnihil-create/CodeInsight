#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a%2 == 0 || b%2 == 0 || c%2 == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << min({a*b, b*c, a*c}) << endl;
    return 0;
}   

/*

3＊5＝15
15*2=30
15*3=45


*/