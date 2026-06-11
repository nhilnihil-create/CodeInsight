#include <iostream>
#include <map>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
int main(void){
    
    int W, H, N;
    cin >> W >> H >> N;
    
    int left_X = 0, right_X = W, bottom_Y = 0, top_Y = H;
    for(int i = 0; i < N; i++){
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1) left_X = max(left_X, x);
        if(a == 2) right_X = min(right_X, x);
        if(a == 3) bottom_Y = max(bottom_Y, y);
        if(a == 4) top_Y = min(top_Y, y);
    }
    
    if(left_X < right_X && bottom_Y < top_Y){
        int ans = (right_X - left_X) * (top_Y - bottom_Y);
        cout << ans << endl;
    }
    else cout << 0 << endl;
    
    
}
