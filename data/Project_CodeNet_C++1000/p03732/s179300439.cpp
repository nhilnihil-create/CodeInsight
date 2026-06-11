#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N,W;
deque<ll> values[4];
ll w[100];
ll v[100];

int main(){
    ll max_v = 0;
    cin >> N >> W;
    ll min_w;
    min_w = 1e10;
    for(int i=0;i<N;i++){
        cin >> w[i] >> v[i];
        min_w = min(min_w,w[i]);
    }
    for(int i=0;i<N;i++){
        values[w[i]-min_w].push_back(v[i]);
    }
    for(int i=0;i<4;i++){
        sort(values[i].begin(),values[i].end(),greater<ll>());
        values[i].push_front(0);
        for(int j=1;j<values[i].size();j++) values[i][j] += values[i][j-1];
    }
    for(int a=0;a<values[0].size();a++){
        for(int b=0;b<values[1].size();b++){
            for(int c=0;c<values[2].size();c++){
                for(int d=0;d<values[3].size();d++){
                    ll sum_v = values[0][a] + values[1][b] + values[2][c] + values[3][d];
                    ll sum_w = a*min_w + b*(min_w+1) + c*(min_w+2) + d*(min_w+3);
                    if(W < sum_w) break;
                    max_v = max(max_v,sum_v);
                }
            }
        }
    }
    cout << max_v << endl;
    return 0;
}