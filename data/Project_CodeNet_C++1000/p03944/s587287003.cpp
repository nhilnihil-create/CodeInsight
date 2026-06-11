#include <bits/stdc++.h>
using namespace std;

int main(){
	int W,H,N;
    cin >> W >> H >> N;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    for(int i = 0; i < N; i++) {
        int x,y,a;
        cin >> x >> y >> a;
        if(a == 1) {
            b = max(b,x);
        }
        if(a == 2) {
            c = max(c,W-x);
        } 
        if(a == 3) {
            d = max(d,y);
        }
        if(a == 4) {
            e = max(e,H-y);
        }
    }
    cout << max(W-b-c,0)*max(H-d-e,0) << endl;
}
