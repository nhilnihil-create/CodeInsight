#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} //配列vにn個の要素を入力する
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> v(1001);
    
    repn(i, 2, n){
        int x = i;
        repn(j, 2, i){
            while(x%j==0){
                v[j]++;
                x /= j;
            }
        }
    }

    ll ans = 1;
    rep(i, 0, v.size()){
        ans = (ans * (v[i] + 1)) % mod;
    }
    cout << ans;
    

    
}