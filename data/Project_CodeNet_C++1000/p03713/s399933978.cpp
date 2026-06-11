#include <bits/stdc++.h>
using namespace std;
 
int main(){
    
    long long h, w;
    cin >> h >> w;
    
    long long ans = h*w;
    
    vector<long long> area(3);
    
    // 回転前と回転後の２通りを試す
    for (int i = 0; i < 2; i++){
        
        // １つの長方形の辺の長さを全探索する
        for (long long t = 1; t < h; t++){
            
            // 縦割りを試す
            area[0] = t * w;
            area[1] = (h-t)*(w/2);
            area[2] = h*w - area[0] - area[1]; // 最後の面積は, 全体の面積から, それまでに計算した面積２つを引けば良い
            
            sort(area.begin(),area.end());
            ans = min (ans, area[2]-area[0]); // mmax - minと現在までの答えを比較せよ
            
            
            // 横割りを試す
            area[0] = t*w;
            area[1] = ((h-t)/2) * w;
            area[2] = h*w - area[0] - area[1];
            
            sort(area.begin(),area.end());
            ans = min(ans, area[2]-area[0]); // mmax - minと現在までの答えを比較せよ
        }
        
        // チョコレートの回転を忘れない!!!
        swap(h,w);
    }
    
    cout << ans << endl;
    return 0;
}