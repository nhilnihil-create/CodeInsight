/*https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b*/

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}


int main(){
    int n,k;
    cin >> n >> k;
    k--;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    if(k==0) {
        cout << 0 << endl;
        return 0;
    }
    n--;
    int bit = (1<<k)-1;
    //cout << bitset<16>(bit) << endl; 
    ll res = 1001001001001;
    for(; bit < (1<<n); bit = next_combination(bit)){
        ll high = a[0];
        ll temp = 0;
        //cout << bitset<16>(bit) << endl; 
        rep(i,n){
            //cout << "i:" << i+1 <<" ";
            if(bit>>i & 1){
                //cout << "yes " << "h: " << high << "a: " << a[i+1] << endl;
                if(high>=a[i+1]){
                    temp+=(high-a[i+1]+1);
                    high++;
                }
                else{
                    high=a[i+1];
                }
            }
            else{
                if(high<a[i+1]) high = a[i+1];
                //cout << "no " << high << endl;
            }

        }
        res = min(temp,res);
    }
    cout << res << endl;
}