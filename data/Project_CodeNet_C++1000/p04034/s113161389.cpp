#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    pair<int, int> p[m];
    for(int i = 0; i < m; i++){
        cin >> p[i].first >> p[i].second;
        p[i].first--;
        p[i].second--;
    }

    int box[n];
    int flag[n];
    for(int i = 0; i < n; i++){
        box[i] = 1;
        flag[i] = 0;
    }
    flag[0] = 1;

    for(int i = 0; i < m; i++){
        if(flag[p[i].first] == 1){
            if(box[p[i].first] == 1){
                flag[p[i].first] = 0;
                flag[p[i].second] = 1;
            }else{
                flag[p[i].second] = 1;
            }
        }
        box[p[i].first]--;
        box[p[i].second]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(flag[i] == 1){
            ans++;
        }
    }

    cout << ans << endl;
}