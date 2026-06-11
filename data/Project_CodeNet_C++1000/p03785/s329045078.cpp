#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,c,k;
    cin >> n >> c >> k;
    int ans = 0;
    int cnt = 0;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t.begin(),t.end(),greater<int>());
    int memo = t[0];
    for(int i = 0; i< n; i++){
        cnt++;
        memo = max(t[i],memo);
        if(t[i]+k < memo){
            ans++;
            cnt = 1;
            memo = t[i];
        }
        else if(cnt == c){
            cnt = 0;
            ans++;
            memo = -1;
        }
    }
    ans += (cnt+c-1)/c;
    cout << ans << endl;
    return 0;
}