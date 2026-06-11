#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(M, vector<char>(M));
    for(int i =0; i < N; i++) for(int j = 0; j < N; j++) cin >> A[i][j];
    for(int i =0; i < M; i++) for(int j = 0; j < M; j++) cin >> B[i][j];

    vector<vector<vector<char>>> A_sub;
    for(int i = 0; i <= N - M; i++){
        for(int j = 0; j <= N - M; j++){
            vector<vector<char>> A_app(M, vector<char>(M));
            for(int k = 0; k < M; k++){
                for(int l = 0; l < M; l++){
                    A_app[k][l] = A[i+k][j+l];
                }
            }
            A_sub.push_back(A_app);
        }
    }
    for(auto v : A_sub){
        if(v == B){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}
