#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int W;
    cin >> n >> W;

    vector<vector<long long int>> w(4);
    long long int w1, v1;
    cin >> w1 >> v1;
    w[0].push_back(v1);
    for(int i=0; i<n-1; i++){
        long long int w2, v2;
        cin >> w2 >> v2;
        w[w2-w1].push_back(v2);
    }
    
    vector<int> size(4);
    for(int i=0; i<4; i++){
        size[i] = w[i].size();
        sort(w[i].begin(),w[i].end());
        reverse(w[i].begin(),w[i].end());

        for(int j=1; j<size[i];j++){
            w[i][j] += w[i][j-1];
        }
        /*
        for(int j=0; j<w[i].size();j++){
            cout << w[i][j] << " ";
        }cout << endl;
        */
    }
    long long int ans = 0;
    for(int i=0; i<=min(n,size[0]); i++){
        for(int j=0; j<=min(n-i,size[1]); j++){
            for(int k=0; k<=min(n-i-j,size[2]); k++){
                for(int l=0; l<=min(n-i-j-k,size[3]); l++){
                    if(w1      * i 
                    + (w1 + 1) * j 
                    + (w1 + 2) * k 
                    + (w1 + 3) * l <= W){
                        long long int value = 0;
                        if(i >= 1) value += w[0][i-1];
                        if(j >= 1) value += w[1][j-1];
                        if(k >= 1) value += w[2][k-1];
                        if(l >= 1) value += w[3][l-1];
                        ans = max(ans, value);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}