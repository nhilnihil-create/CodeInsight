#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N, ans = 0;
    cin >> N;
    vector<ll> vec(3 * N,0);
    for(int i = 0; i < 3 * N; i++) cin >> vec[i];
    sort(vec.begin(),vec.end() ,greater<ll>());
    for(int i = 0; i < 2 * N; i += 2){
        vec[i] = 0;
        vec[3 * N - i];
        ans += vec[i + 1];
        vec[i + 1] = 0;
    }
    
    cout << ans << endl;
}
