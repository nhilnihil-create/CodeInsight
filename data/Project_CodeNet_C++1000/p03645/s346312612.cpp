#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>h(200001);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        h[b].push_back(a);
        if(b==n){
            for(int i=0; i<h[a].size(); i++){
                if(h[a][i]==1){
                    puts("POSSIBLE");
                    return 0;
                }
            }
        }
    }

    for(int i=0; i<h[n].size(); i++){
        int t = h[n][i];
        for(int j=0; j<h[t].size(); j++){
            if(h[t][j]==1){
                puts("POSSIBLE");
                return 0;
            }
        }
    }

    puts("IMPOSSIBLE");
    
    return 0;
}