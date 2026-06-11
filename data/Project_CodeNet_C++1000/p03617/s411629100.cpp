#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll Q,H,S,D;
    cin >> Q >> H >> S >> D;
    ll N;
    cin >> N;
    N *= 4;
    ll ans = 0;
    ll phase_1 = N / 8;
    
    ans += min(D, min(S * 2, min(H * 4, Q * 8))) * phase_1;
    
    N -= phase_1 * 8;
    
    ll phase_2 = N / 4;
    
    ans += min(S, min(H * 2, Q * 4)) * phase_2;
    
    N -= phase_2 * 4;
    
    ll phase_3 = N / 2;
    
    ans += min(H, Q * 2) * phase_3;
    
    N -= phase_3 * 2;
    
    ll phase_4 = N;
    
    ans += Q * phase_4;
    
    cout << ans << endl;
}
