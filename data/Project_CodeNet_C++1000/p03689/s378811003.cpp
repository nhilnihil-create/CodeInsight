#include <bits/stdc++.h>
using namespace std;
int main(){
    int H, W, h, w;
    cin>>H>>W>>h>>w;
    if(H%h==0 && W%w==0) {
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<'\n';
    int pval=(W/w)*(H/h)*2;
    int nval=-pval*(w*h-1)-1;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            if(j%w==0 && i%h==0) {
                cout<<nval;
            } else {
                cout<<pval;
            }
            if(j!=W) {
                cout<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}
