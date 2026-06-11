#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp, mp2;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        mp[x]++;
        mp2[x%m]++;
    }

    int ans = 0;
    for(int i=0;i<m;++i){
        if(i == 0 || (m%2 == 0 && i == m/2)){
            int p = mp2[i] / 2;
            ans += p;
            mp2[i] -= 2*p;
        }else{
            int p = min(mp2[i], mp2[m-i]);
            ans += p;
            mp2[i] -= p;
            mp2[m-i] -= p;
        }
    }
    for(auto e: mp){
        if(mp2[e.first%m] < 2 || e.second < 2)continue;
        int p = min(e.second / 2, mp2[e.first%m] / 2);
        ans += p;
        mp2[e.first%m] -= 2*p;
    }

    cout << ans << endl;

    return 0;
}