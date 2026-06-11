#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // DP
    vector<vector<int>> former(n+2, vector<int>(k+1)), latter(n+2, vector<int>(k+1));
    former[0][0] = 1;
    latter[n+1][0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j - a[i] >= 0) former[i+1][j] = max(former[i+1][j], former[i][j - a[i]]);
            former[i+1][j] = max(former[i+1][j], former[i][j]);
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=k; j++){
           if(j - a[i] >= 0) latter[i+1][j] = max(latter[i+1][j], latter[i+2][j - a[i]]);
            latter[i+1][j] = max(latter[i+1][j], latter[i+2][j]);
        }
    }

    // cumulative sum
    for(int i=0; i<n+2; i++){
        for(int j=0; j+1<=k; j++){
            latter[i][j+1] += latter[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        bool flag = false;
        for(int j=0; j<k; j++){
            if(former[i][j] == 1){
                int test = latter[i+2][k-1-j];
                if(k-a[i]-1-j >= 0) test -= latter[i+2][k-a[i]-1-j];
                
                if(test > 0) flag = true;
            }
        }
        if(flag == false) ans += 1;
    }
    cout << ans << endl;
    return 0;
}