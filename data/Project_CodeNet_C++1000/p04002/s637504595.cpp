#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> P;

lint H, W, N, cnt[10];
map<P, lint> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> H >> W >> N;
    for(int i=0;i<N;i++){
        lint a, b; cin >> a >> b;
        for(lint j=max(1LL, a-2);j<=min(a, H-2);j++) for(lint k=max(1LL, b-2);k<=min(b, W-2);k++) mp[P(j, k)]++;
    }

    cnt[0] = (H-2) * (W-2);
    for(auto it : mp) {cnt[it.second]++; cnt[0]--;}

    for(int i=0;i<10;i++) cout << cnt[i] << endl;
    return 0;
}