#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 40;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int H,W; cin >> H >> W;
    if(H%3==0 || W%3==0) cout << 0 << endl;
    else{
        int h = H/3;
        int w = W/3;
        int c1 = max(h*W,max((H-h)*(W/2),(H-h)*(W-W/2)))
            -min(h*W,min((H-h)*(W/2),(H-h)*(W-W/2)));
        int c2 = max(w*H,max((W-w)*(H/2),(W-w)*(H-H/2)))
            -min(w*H,min((W-w)*(H/2),(W-w)*(H-H/2)));
        int c3 = H;
        int c4 = W;
        int c5 = max((h+1)*W,max((H-h-1)*(W/2),(H-h-1)*(W-W/2)))
            -min((h+1)*W,min((H-h-1)*(W/2),(H-h-1)*(W-W/2)));
        int c6 = max((w+1)*H,max((W-w-1)*(H/2),(W-w-1)*(H-H/2)))
            -min((w+1)*H,min((W-w-1)*(H/2),(W-w-1)*(H-H/2)));
        cout << min(min(min(c1,min(c2,min(c3,c4))),c5),c6) << endl;

    }
    return 0;
}