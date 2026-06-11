#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    map<int ,int > mp;
    rep(i,3){
        int k;  cin >> k;
        mp[k]++;
    }

    if(mp[5]==2 && mp[7]==1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}