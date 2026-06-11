#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> x(n);

    int cnt[100010] = {};
    int cnt2[100010] = {};
    int tmp[100010] = {};

    for(int i = 0;i < n;i++){
        cin >> x[i];
        cnt[x[i] % m]++;
        tmp[x[i]]++;
    }

    for(int i = 1;i <= 100010;i++){
        cnt2[i%m] += tmp[i]/2;
    }

    int ans = 0;
    for(int i = 1;i <= m/2;i++){
        int l = i;
        int r = m-i;
        if(l == r){
            ans += cnt[l] / 2;
        }else{
            if(cnt[l] < cnt[r]) swap(l, r);
            ans += cnt[r];
            int ho = cnt[l] - cnt[r];
            ans += min(ho/2, cnt2[l]);
        }
    }
    ans += cnt[0]/2;

    cout << ans << endl;
    return 0;
}