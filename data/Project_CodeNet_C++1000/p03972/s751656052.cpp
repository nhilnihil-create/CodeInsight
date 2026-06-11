#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int W, H;
    cin >> W >> H;
    vector<pair<int, int>> pq;
    for(int i=0; i<W; i++){
        int p;
        cin >> p;
        pq.push_back(make_pair(p, 0));
    }
    for(int i=0; i<H; i++){
        int q;
        cin >> q;
        pq.push_back(make_pair(q, 1));
    }
    int cnt0 = 0;
    int cnt1 = 0;
    sort(pq.begin(), pq.end());
    long long ans = 0;
    for(int i=0; i<pq.size(); i++){
        if(pq[i].second == 0){
            long long tmp = H+1-cnt1;
            if(tmp <= 0) break;
            ans += tmp * pq[i].first;
            cnt0++;
        }else{
            long long tmp = W+1-cnt0;
            if(tmp <= 0) break;
            ans += tmp * pq[i].first;
            cnt1++;
        }
    }
    cout << ans << endl;
    return 0;
}
