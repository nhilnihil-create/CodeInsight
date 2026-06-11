#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 1e18LL

const ll MAX = 1000000000000000000; //1e18

int main(){
    string a, b;
    ll x = 0;
    cin >> a >> b;
    if(a.size() > b.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    else if(a.size() < b.size()) {
        cout << "LESS" << endl;
        return 0;
    }
    else{
        rep(i, a.size()){
            if(a[i] > b[i]){
                cout << "GREATER" << endl;
                return 0;
            }else if(a[i] < b[i]){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }

}
