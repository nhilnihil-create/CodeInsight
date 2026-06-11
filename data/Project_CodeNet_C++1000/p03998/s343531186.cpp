#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll binPow(ll x, ll y, ll md = mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1){
            res = (res * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve(){
   string a, b, c;
   cin >> a >> b >> c;
   char now = 'a';
   int index_a = 0, index_b = 0, index_c = 0;
   while(true){
       if(now == 'a'){
           if(a.size() == index_a){
               cout << "A\n";
               break;
           }
           now = a.at(index_a++);
       }
       else if(now == 'b'){
           if(b.size() == index_b){
               cout << "B\n";
               break;
           }
           now = b.at(index_b++);
       }
       else{
           if(c.size() == index_c){
               cout << "C\n";
               break;
           }
           now = c.at(index_c++);
       }
   }
 }

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
