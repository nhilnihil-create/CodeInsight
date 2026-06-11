#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)
long INF =  __LONG_MAX__ /2;

int main() {
    int N;
    cin>>N;
    vector<vector<int>> A(N, vector<int> (N, 0));
    REP(i, 0, N) REP(j, 0, N){
        cin >> A[i][j];
    } 
    

    vector<vector<long>> M(N, vector<long> (N, INF));
    vector<vector<long>> MAP(N, vector<long> (N, 0));
    REP(i, 0, N){
        REP(j, 0, N){
            REP(k, 0, N){
                long new_path = A[i][k] + A[k][j];
                if(new_path < M[i][j]){
                    M[i][j] = new_path;
                } 
            }
        }
    }
    REP(i, 0, N){
        REP(j, 0, N){
            MAP[i][j] = M[i][j];
            REP(k, 0, N){
                if(A[i][j] == M[i][k] + M[k][j] && i != k && j != k){
                    MAP[i][j] = 0;
                }
            }
        }
    }
    
    long ans = 0;
    REP(i, 0, N){
        REP(j, 0, N){
            if(M[i][j] != A[i][j]){
                ans = -1;
                break;
            }
            ans += MAP[i][j];
        }
        if(ans < 0) break;
    }

    if(ans>=0) ans /= 2;
    cout << ans << endl;
}
