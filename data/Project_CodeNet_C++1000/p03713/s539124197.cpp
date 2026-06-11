#include <iostream>

using namespace std;

typedef long long ll;

ll H,W;

int main(){
    ll ans = 1e10;
    cin >> H >> W;
    for(int i=1;i<=H-1;i++){
        ll S1 = i * W;
        ll S2 = (H-i)/2 * W;
        ll S3 = (H-i - (H-i)/2) * W;
        ll M = max(S3,max(S1,S2));
        ll N = min(S3,min(S1,S2));
        ans = min(ans,M-N);
        S2 = W/2 * (H-i);
        S3 = (W - W/2) * (H-i);
        M = max(S3,max(S1,S2));
        N = min(S3,min(S1,S2));
        ans = min(ans,M-N);
    }
    ll a = H;
    H = W;
    W = a;
    for(int i=1;i<=H-1;i++){
        ll S1 = i * W;
        ll S2 = (H-i)/2 * W;
        ll S3 = (H-i - (H-i)/2) * W;
        ll M = max(S3,max(S1,S2));
        ll N = min(S3,min(S1,S2));
        ans = min(ans,M-N);
        S2 = W/2 * (H-i);
        S3 = (W - W/2) * (H-i);
        M = max(S3,max(S1,S2));
        N = min(S3,min(S1,S2));
        ans = min(ans,M-N);
    }
    cout << ans << endl;
    return 0;
}