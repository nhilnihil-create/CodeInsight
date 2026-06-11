#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
constexpr ll MOD = ll(1e9+7);
constexpr int MAX_X = 1e5+5;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(MAX_X,0), ev(m,0), od(m,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i=0;i<MAX_X;i++){
        od[i%m] += cnt[i]&1;
        ev[i%m] += cnt[i]-cnt[i]%2;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int j = (m-i%m)%m;
        if(i != j){
            int k = min(od[i]+ev[i], od[j]+ev[j]);
            ans += k;
            if(od[i] < k){
                ev[i] -= k-od[i];
                od[i] = 0;
            }
            else{
                od[i] -= k;
            }
            if(od[j] < k){
                ev[j] -= k-od[j];
                od[j] = 0;
            }
            else{
                od[j] -= k;
            }
        }
        else{
            ans += (od[i]+ev[i])/2;
            od[i] = 0;
            ev[i] = 0;
        }
    }
    for(int i=0;i<m;i++){
        ans += ev[i]/2;
    }
    cout << ans << endl;
    return 0;
}