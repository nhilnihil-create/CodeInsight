#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;

int main(){
    int  H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> cs;
    rep(i, N){
        int x, y;
        cin >> y >> x;
        for(int i = max(1, y - 2); i <= min(H - 2, y); i ++){
            for(int j = max(1, x - 2); j <= min(W - 2, x); j ++){
                pair<int, int> c = {j, i};
                cs.push_back(c);
            }
        }
    }

    sort(cs.begin(), cs.end());

    vector<ll> num(10);
    for(int i = 0; i < cs.size(); ){
        int cnt = 1;
        for(ll j = i + 1; j < cs.size(); j ++){
            if(cs[i].first == cs[j].first && cs[i].second == cs[j].second){
                cnt ++;
            }else{
                break;
            }
        }
        num[cnt] ++;
        i += cnt;
    }

    num[0] = 1L * (H - 2) * (W - 2);

    for(int i = 1; i < num.size(); i ++){
        num[0] -= num[i];
    }

    rep(i, num.size()){
        cout << num[i] << endl;
    }

    return 0;
}
