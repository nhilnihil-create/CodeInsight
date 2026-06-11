#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
    }
    auto v2 = v;
    sort(v2.begin(), v2.end());
    map<int, int> mp;
    for(int i=0;i<n;++i){
        mp[v2[i]] = i;
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        if(i%2 != mp[v[i]]%2)ans++;
    }
    ans /= 2;

    cout << ans << endl;

    return 0;
}
