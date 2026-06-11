
#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
int N, K;
int A[5010] = {};
bool dp[5010][5010] = {}; // dp[i番目まで][和がちょうどj] = 可能？
bool necessary(int m){ // m番目を除いて[K-A[m], K)の値を作れるか？
    int c=A[m];
    A[m]=0;
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    
    for(int i = 0; i < N; i++){
        
        for(int j = K-1; j>=0; j--){
            if(j-A[i]>=0&&dp[i][j-A[i]]==true){
                dp[i+1][j]=true;
            }else if(dp[i][j]==true){
                dp[i+1][j]=true;
            }
            }
       
    }
    bool ans = false;
    for(int a = max(K - c, 0); a < K; a++){
        if(dp[N][a]){ans = true;}
    }
    A[m]=c;
    return ans;
}



int main() {
    cin >> N >> K;
    for(int i = 0; i <N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    // a<bでaが必要かつbが不必要とすると矛盾．
    // aが属し，K<=(Sの元の和)<K+aなるSを1つとる．bがSの元のときはSそのものが，
    // bがSの元でないときはSからaを除きbを加えたものが反例．
    if(necessary(0)){cout << 0 << endl;}
    else if(!necessary(N-1)){cout << N << endl;}
    else{
        int L = 1, R = N;
        while(R - L > 1){
            int M = (L + R) / 2;
            if(necessary(M-1)){R = M;}
            else{L = M;}
        }
        cout << L << endl;
    }
}
