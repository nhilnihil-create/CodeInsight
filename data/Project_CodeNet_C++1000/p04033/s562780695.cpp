#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    ll a, b;
    cin >> a >> b;
    if(a <= 0 && b >= 0){
        cout << "Zero" << endl;
    }else if(b < 0 && (b - a + 1) % 2 != 0){
        cout << "Negative" << endl;
    }else{
        cout << "Positive" << endl;
    }
}