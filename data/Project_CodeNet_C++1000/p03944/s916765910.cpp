#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int w,h,n;
    cin >> w >> h >> n;
    vector<vector<bool>> p(h, vector<bool>(w, true));
    for(int i = 0; i < n; i++) {
        int x,y,a;
        cin >> x >> y >> a;
        if(a==1){
            for(int j = 0; j < h; j++) {
                for(int k = 0; k < x; k++) {
                    p.at(j).at(k)=false;
                }
            }
        }
        if(a==2){
            for(int j = 0; j < h; j++) {
                for(int k = x; k < w; k++) {
                    p.at(j).at(k)=false;
                }
            }
        }
        if(a==3){
            for(int j = 0; j < y; j++) {
                for(int k = 0; k < w; k++) {
                    p.at(j).at(k)=false;
                }
            }
        }
        if(a==4){
            for(int j = y; j < h; j++) {
                for(int k = 0; k < w; k++) {
                    p.at(j).at(k)=false;
                }
            }
        }
    }
    int ans=0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(p.at(i).at(j)==true) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}