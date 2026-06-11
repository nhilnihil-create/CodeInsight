#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;



long long W, H;
pair<long long, int> pq[200000];


int main(){
    cin >> W >> H;
    for(int i = 0; i < W; i++){
        long long p;
        cin >> p;
        pq[i] = make_pair(p, 0);
    }
    for(int j = 0; j < H; j++){
        long long q;
        cin >> q;
        pq[j + W] = make_pair(q, 1);
    }
    sort(pq, pq+W+H);

    long long ans = 0, h = H, w = W;
    for(int i = 0; i < W+H; i++){
        long long dist = pq[i].first;
        int direction = pq[i].second;
        // cout << dist << ", " << direction << endl;
        if(direction == 0){
            ans += (h+1) * dist;
            w--;
        }else{
            ans += (w+1) * dist;
            h--;
        }
    }
    cout << ans << endl;
}