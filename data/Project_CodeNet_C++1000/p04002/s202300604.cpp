#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int H,W,N;

int main(){
    cin>>H>>W>>N;

    map<pair<int,int>,int> black;
    int x,y;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d",&x,&y); x--; y--;
        for (int j = -2; j <= 0; ++j) {
            for (int k = -2; k <= 0; ++k) {
                if(x+j<0 || x+j+2>H-1 || y+k<0 || y+k+2>W-1)continue;
                black[make_pair(x+j, y+k)]++;
            }
        }
    }

    vector<ll> cnt(10,0ll);

    for(auto itr=black.begin();itr!=black.end();++itr){
        for (int i = 0; i < 10; ++i) {
            if((itr->second)==i) cnt[i]++;
        }
    }

    cnt[0]=(ll)(H-2)*(W-2);
    for (int i = 1; i < 10; ++i) {
        cnt[0]-=(ll)cnt[i];
    }
    for (int i = 0; i < 10; ++i) {
        cout<<cnt[i]<<endl;
    }

    return 0;
}