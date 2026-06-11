#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        mp[a+1]++;
        mp[a]++;
        mp[a-1]++;
    }
    int ans = 0;
    for(int i=-1; i<=100000; i++){
        ans = max(mp[i], ans);
    }
    cout << ans << endl;
    return 0;
}