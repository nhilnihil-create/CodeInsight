#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int max_s = 0;
    vector<int> s;
    for (int i=0; i<N; i++){
        int in;
        cin >> in;
        max_s = max(max_s, in);
        s.push_back(in);
    }
    int M = max_s * N;
    vector<bool> dp(M+1);
    for (int i=1; i<=M; i++){
        dp[i] = false;
    }
    dp[0] = true;

    for (auto x : s){
        for (int i=M; i>=0; i--){
            if (i >= x && dp[i-x]){
                dp[i] = true;
            }
        }
    }
    for (int i=0; i<=M; i++){
        if ((M-i)%10 != 0 && dp[M-i]){
            cout << M-i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}