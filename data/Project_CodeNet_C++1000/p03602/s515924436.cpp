#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>

using namespace std;

long long d[300][300];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> d[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(i == j || j == k || i == k){
                    continue;
                }
                if(d[j][i] + d[i][k] < d[j][k]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            bool exists_mid_point = false;
            for(int k = 0; k < N; k++){
                if(i == k || j == k){
                    continue;
                }
                if(d[i][k] + d[k][j] == d[i][j]){
                    exists_mid_point = true;
                    break;
                }
            }
            if(!exists_mid_point){
                ans += d[i][j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
