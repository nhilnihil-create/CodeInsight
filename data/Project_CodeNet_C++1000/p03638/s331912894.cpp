#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

int main(){
    int h, w, n; cin >> h >> w >> n;
    vector<int> as(n);
    for(int i=0; i<n; ++i){
        cin >> as[i];
    }
    vector<vector<int>> ans(h, vector<int>(w));
    int ai=0;
    for(int hi=0; hi<h; ++hi){
        if(hi%2==0){
            for(int wi=0; wi<w; ++wi){
                ans[hi][wi]=ai+1;
                --as[ai];
                if(as[ai]==0) ++ai;
            }
        } else{
            for(int wi=w-1; wi>=0; --wi){
                ans[hi][wi]=ai+1;
                --as[ai];
                if(as[ai]==0) ++ai;
            }
        }
    }
    for(int hi=0; hi<h; ++hi){
        for(int wi=0; wi<w; ++wi){
            cout << ans[hi][wi] << (wi==w-1 ? '\n' : ' ');
        }
    }
    return 0;
}
