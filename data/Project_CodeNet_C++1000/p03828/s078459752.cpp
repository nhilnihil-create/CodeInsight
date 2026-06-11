#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6+5;

const int mod = 1e9+7;

int main(){
    int x;
    cin >> x;
    map < int , int > cnt;
    for(int i = 1; i <= x; i++){
        //I
        int cur_num = i;
        for(int j = 2; j*j <= cur_num; j++){
            while(cur_num % j == 0){
                cur_num /= j;
                cnt[j] ++;
            }
        }
        if(cur_num != 1){
            cnt[cur_num]++;
        }
    }
    ll ans = 1;
    map < int , int > :: iterator it = cnt.begin();
    for(; it != cnt.end(); it++){
        ans = (ans * ((it)->second + 1)) % mod;
        ans %= mod;

    }
    cout << ans << "\n";
}
