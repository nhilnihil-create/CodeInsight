#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using P = pair<LL, LL>;

int main(){
    LL H, W, N;
    cin >> H >> W >> N;
    map<P, LL>  Map;
    for(int i = 0;i < N;i++){
        int ai, bi;
        cin >> ai >> bi;
        for(int i = ai-2;i <= ai;i++){
            for(int j = bi-2;j <= bi;j++){
                if(i < 1 || i > H || j < 1 || j > W)    continue;
                if(i+2 > H) continue;
                if(j+2 > W) continue;
                P p = P(i, j);
                if(!Map[p]) Map[p] = 1;
                else    Map[p]++;
            }
        }
    }
    vector<LL>  ans(10, 0);
    ans[0] = (H-2)*(W-2);
    for(auto& iter : Map){
        ans[iter.second]++;
        ans[0]--;
    }
    for(auto& iter : ans)   cout << iter << endl;
}