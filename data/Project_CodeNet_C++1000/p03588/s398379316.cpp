// AtCoder template
// sabaより胡蝶しのぶさんの方が可愛いのではないか？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    ll a,b,a_max = -1, b_last;
    rep(i,n){
        cin >> a >> b;
        if(a_max < a){
            a_max = a;
            b_last = b;
        }
    }
    cout << a_max + b_last << endl;
}