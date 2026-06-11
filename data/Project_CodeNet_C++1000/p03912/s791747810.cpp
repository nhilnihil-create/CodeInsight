#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> G[100000];
int cnt_same[100000];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int X;
        cin >> X;
        G[X%M].push_back(X);
    }
    for(int i = 0; i < M; i++){
        if(G[i].size() == 0) continue;
        sort(G[i].begin(), G[i].end());
        int prev = G[i][0];
        int cnt = 1;
        for(int j = 1; j < G[i].size(); j++){
            if(G[i][j] == prev) {
                cnt++;
                if(j == G[i].size()-1){
                    cnt_same[i] += (cnt/2)*2;
                }
            }
            else{
                cnt_same[i] += (cnt/2)*2;
                cnt = 1;
                prev = G[i][j];
            }
        }
    }
    int ans = 0;
    ans += G[0].size()/2;
    if(M%2 == 0) ans += G[M/2].size()/2;
    for(int i = 1; i < (M+1)/2 ; i++){
        //cout << G[i].size() << ' ' << G[M-i].size() << endl;
        if(G[i].size() > G[M-i].size()){
            ans += G[M-i].size();
            ans += min((int)(G[i].size()-G[M-i].size()), cnt_same[i])/2;
        }else{
            ans += G[i].size();
            //cout << ans << endl;
            ans += min((int)(G[M-i].size()-G[i].size()), cnt_same[M-i])/2;
            //cout << ans << endl;
        }
    }
    //cout << cnt_same[9] << endl;
    cout << ans << endl;
}