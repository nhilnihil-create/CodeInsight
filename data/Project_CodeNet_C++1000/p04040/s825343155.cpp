#include <iostream>
using namespace std;
typedef long long ll;
ll f[200001], M=1e9+7;
ll p(ll a, ll b){
    if(b==0)return 1;
    if(b%2==0)return p((a*a)%M, b/2);
    return (a*p(a, b-1))%M;
}
ll c(int a, int b){
    return ((f[a]*p(f[b], M-2))%M * p(f[a-b], M-2))%M;
}
int main() {
    ll h, w, a, b, ans=0;
    cin >> h >> w >> a >> b;
    f[0] = 1;
    for(int i=1;i<200001;i++){
        f[i] = (f[i-1] * i) % M;
    }
    for(int i=h-a;i>0;i--){
        int x=b+1+h-a-i;
        
        if(x>w)break;
        ans += (c(i+x-2, i-1) * c(h-i+w-x, h-i))%M;
        ans %= M;
    }
    cout << ans << endl;
	return 0;
}