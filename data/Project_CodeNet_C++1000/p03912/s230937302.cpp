#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N, M;  cin >> N >> M;
    vector<int> X(N);
    map<int, vector<int>> mp;
    for(int i=0; i<N; i++){
        cin >> X[i];
        mp[X[i]%M].push_back(X[i]);
    }

    ll ans = 0;
    for(int i=0; i<=M/2; i++){
        ll cnt = mp[i].size();
        if(i==0 || (M%2==0 && i == M/2)){
            ans += cnt/2;
        }else{
            ll cnt2 = mp[M-i].size();
            int selected, other, delta;
            if(cnt < cnt2){
                selected = M-i;
                other = i;
                delta = (cnt2 - cnt)/2;
            }else{
                selected = i;
                other = M-i;
                delta = (cnt - cnt2)/2;
            }

            map<int, int> ccc;
            for(int j : mp[selected]){
                ccc[j]++;
            }
            int tmp = 0;
            for(auto p : ccc){
                tmp += p.second/2;
            }
            ans += min(tmp, delta) + mp[other].size();
        }
    }
    cout << ans << endl;
}
