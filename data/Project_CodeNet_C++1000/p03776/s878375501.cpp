#include<bits/stdc++.h>
using namespace std;
const int SIZE = 55;
long long dp[SIZE][SIZE];
void make_pascal_triangle(){//パスカルの三角形を使って求める　O(n^2).
    for (int i = 0; i < SIZE; i++){
        dp[i][0] = dp[0][i] = 1;
    }
    for (int i = 1; i < SIZE; i++){
        for (int j = 1; j < SIZE; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }  
    }
}

long long C (int n, int k){//nCkを求める
    return dp[n-k][k];
}


int main(){
    make_pascal_triangle();
    int n, a, b; cin >> n >> a >> b;
    vector<long long> A;
    for (int i = 0; i < n; i++){
        long long v; cin >> v;
        A.push_back(v);
    }
    sort(A.begin(), A.end());
    double ave = 0;
    for (int i = 0; i < a; i++){
        ave += A[n-i-1];
    }
    ave /= a;
    cout << fixed << setprecision(7) << ave << endl;
    if (A[n-a] != A[n-1])
    {
        int cnt_0 = 0;
        for (int i = 1; i <= a; i++){
            cnt_0 += A[n-i] == A[n-a]; 
        }
        int cnt_1 = 0;
        for (int i = 1; i <= n; i++){
            cnt_1 += A[n-i] == A[n-a];
        }
        cout << C(cnt_1, cnt_0) << endl;
    }
    else{
        long long ans = 0;
        int cnt_1 = 0;
        for (int i = 1; i <= n; i++){
            cnt_1 += A[n-i] == A[n-a];
        }
        for (int i = a; i <= b; i++){
            if(A[n-a] == A[n-i])
                ans += C(cnt_1, i);
        }
        cout << ans << endl;
    }
    
}