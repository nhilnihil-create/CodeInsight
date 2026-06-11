#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    long long H,W;
    cin >> H >> W;
    //even * even
    long long S = H * W;
    long long res=LONG_LONG_MAX;
    for(int i=1;i<W;i++){
        long long S1 = H*i;
        //
        long long ma=S1,mi=S1;
        long long S2 = (H/2) * (W-i);
        ma=max(ma,S2),mi=min(mi,S2);
        long long S3 = S - S1 - S2;
        ma=max(ma,S3),mi=min(mi,S3);
        res=min(res,ma-mi);
        //
        ma=S1,mi=S1;
        S2 = ((W-i)/2) * H;
        ma=max(ma,S2),mi=min(mi,S2);
        S3 = S - S1 - S2;
        ma=max(ma,S3),mi=min(mi,S3);
        res=min(res,ma-mi);
    }
    swap(W,H);
    for(int i=1;i<W;i++){
        long long S1 = H*i;
        //
        long long ma=S1,mi=S1;
        long long S2 = (H/2) * (W-i);
        ma=max(ma,S2),mi=min(mi,S2);
        long long S3 = S - S1 - S2;
        ma=max(ma,S3),mi=min(mi,S3);
        res=min(res,ma-mi);
        //
        ma=S1,mi=S1;
        S2 = ((W-i)/2) * H;
        ma=max(ma,S2),mi=min(mi,S2);
        S3 = S - S1 - S2;
        ma=max(ma,S3),mi=min(mi,S3);
        res=min(res,ma-mi);
    }
    cout << res << endl;

    return 0;
}