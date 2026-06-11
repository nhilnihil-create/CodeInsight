#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int W,H;
bool box_is_in_range(int p, int q){
    // (p,q) is the upper left point of the 3*3 box //
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){  // check all 9 points in the box
            if(p+i < 1 || q+j < 1 || p+i > W || q+j > H) return false;
        }
    }
    return true;
}

int main(){
    int N;
    cin >> H >> W >> N;
    map<pair<long long,long long>,long long> mp;

    for(int i=0;i<N;i++){
        long long a,b;
        cin >> a >> b;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(a-k >= 1 && a-k <= H-2 && b-l >= 1 && b-l <= W-2){
                    mp[make_pair(a-k,b-l)]++;
                }
            }
        }
    }

    long long ans[10];
    fill(ans, ans+10,0);

    ans[0] = 1ll * (H-2)*(W-2);

    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        ans[itr->second]++;
        ans[0]--;
    }

    for(int i=0;i<10;i++){
        cout << ans[i] << endl;
    }

    return 0;
}