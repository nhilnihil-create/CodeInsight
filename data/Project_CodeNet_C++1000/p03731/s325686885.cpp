#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n,t;
    cin >> n >> t;
    ll time = 0;
    ll sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(time + t <= a){
            sum += t;//前のやつについて
            time = a;
        }else{
            sum += a - time;
            time = a;
        }
    }
    sum += t;
    cout << sum << endl;
}