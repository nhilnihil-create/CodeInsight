#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long W, H;
    long p[100000];
    long q[100000];
    cin >> W >> H;
    for(int i = 0; i < W; i++){
        cin >> p[i];
    }
    for(int i = 0; i < H; i++){
        cin >> q[i];
    }
    sort(p, p+W);
    sort(q, q+H);
    long cnt_w = 0;
    long cnt_h = 0;
    long ans = 0;
    for(int i = 0; i < H+W; i++){
        //cout << cnt_w << ' ' << cnt_h << endl;
        if(cnt_w == W){
            ans += q[cnt_h];
            cnt_h++;
        }else if(cnt_h == H){
            ans += p[cnt_w];
            cnt_w++;
        }
        else if(p[cnt_w] < q[cnt_h]){
            ans += p[cnt_w]*(H+1-cnt_h);
            cnt_w++; 
        }else{
            ans += q[cnt_h]*(W+1-cnt_w);
            cnt_h++; 
        }
    }
    cout << ans << endl;
}