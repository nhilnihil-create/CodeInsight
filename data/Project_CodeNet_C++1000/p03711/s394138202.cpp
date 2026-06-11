#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a[] = {1, 3, 5, 7, 8, 10, 12};
    int b[] = {4, 6, 9, 11};

    int x, y;
    cin >> x >> y;
    if((x == 2) || (y == 2)) cout << "No" << endl;
    else{
        bool ok = false;
        for(auto v: a){
            if(x == v){
                for(auto w: a){
                    if(y == w) ok = true;
                }
            }
        }
        for(auto v: b){
            if(x == v){
                for(auto w: b){
                    if(y == w) ok = true;
                }
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}