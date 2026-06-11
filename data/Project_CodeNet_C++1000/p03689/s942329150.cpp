#include <bits/stdc++.h>
using namespace std;

void fail(){
    cout << "No" << endl;
    exit(0);
}

int main(){
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if(H%h==0 && W%w==0) fail();
    int MX = 1e9-1;
    int a = MX/(h*w-1);
    cout << "Yes" << endl;
    for(int i=0; i<H; i++) for(int j=0; j<W; j++){
        int v = a;
        if(i%h==h-1 && j%w==w-1) v = -a*(h*w-1)-1;
        cout << v << " \n"[j==W-1];
    }
}