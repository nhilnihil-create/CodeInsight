#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = -1;

int main(){
    int n;
    long long ans = 0;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            ans += a[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(k == i || a[i][k] == INF) continue;
            for(int j = 0; j < n; j++){
                if(k == j || i == j || a[k][j] == INF) continue;
                if(a[i][k] + a[k][j] < a[i][j]){
                    cout << -1 << endl;
                    return 0;
                }else if(a[i][k] + a[k][j] == a[i][j]){
                    ans -= a[i][j];
                    a[i][j] = INF;
                }
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
