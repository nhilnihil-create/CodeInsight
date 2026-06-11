#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
    int n,k;
    ll ans = -(1LL<<60);
    cin >> n >> k;
    vector<ll> a(n),s1(n+1,0),s2(n+1,0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        s1[i+1] = s1[i] + a[i];
        if(a[i] >= 0) s2[i+1] = s2[i] + a[i];
        else s2[i+1] = s2[i];
    }
    for(int i = 0;i + k <= n;i++){
        int left = i,right = i+k;
        ll tmp = (s2[left]-s2[0]) + max(0LL,s1[right]-s1[left]) + (s2[n] - s2[right]);
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
