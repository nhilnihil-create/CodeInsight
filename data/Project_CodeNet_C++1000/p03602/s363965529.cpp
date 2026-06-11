#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int N,A[300][300];
    ll sum = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> A[i][j];
            if(i < j)sum += A[i][j];
        }
    }
    bool flag[300][300];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                if(i == j || j == k || k == i)continue;
                if(j > k)continue;                
                if(A[j][k] > A[j][i] + A[i][k]){
                    cout << -1 << endl;
                    return 0;
                }
                if(!flag[j][k] && A[j][k] == A[j][i] + A[i][k]){
                    sum -= A[j][k];
                    flag[j][k] = 1;
                }
            }
        }
    }    cout << sum << endl;
}   