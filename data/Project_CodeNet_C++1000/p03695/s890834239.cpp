#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    vector<int> a(N);
    for(auto& x: a) cin >> x;
    unordered_map<string,int> mp;
    for(int i = 0; i < N; ++i){
        if     (   1 <= a[i] && a[i] <=  399) ++mp["gray"];
        else if( 400 <= a[i] && a[i] <=  799) ++mp["brown"];
        else if( 800 <= a[i] && a[i] <= 1199) ++mp["green"];
        else if(1200 <= a[i] && a[i] <= 1599) ++mp["mizu"];
        else if(1600 <= a[i] && a[i] <= 1999) ++mp["blue"];
        else if(2000 <= a[i] && a[i] <= 2399) ++mp["yellow"];
        else if(2400 <= a[i] && a[i] <= 2799) ++mp["orange"];
        else if(2800 <= a[i] && a[i] <= 3199) ++mp["red"];
        else ++mp["over"];
    }
    for(auto x: mp){
        if(x.first != "over") ++ans;
    }
    if(mp["over"] != 0){
        cout << max((int)ans,(int)1) << " " << ans + mp["over"] << endl;
    }
    else cout << ans << " " << ans << endl;
    return 0;
}