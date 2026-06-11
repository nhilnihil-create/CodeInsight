#include <bits/stdc++.h>
using namespace std;
int main() {
    char g[101][101];
    int n , m; cin>>n>>m;
    for(int i = 1 ; i <= n; ++i){
        for(int j = 1 ; j <= m; ++j){
            cin>>g[i][j];
        }
    }
    for(int i = 1 ; i <= 2 * n ; i++){
       for(int j = 1 ; j <= m; ++j){
          cout << g[(i + 1) / 2][j]<<"";
       }
       cout << endl;
    }

}