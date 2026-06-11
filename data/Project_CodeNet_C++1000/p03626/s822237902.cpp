#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)


int main() {
    int N;
    int M = 1000000007;
    cin >> N;
    if(N == 1){
        cout << 3 << endl;
        return 0;
    }
    string S1,S2;
    cin >> S1;
    cin >> S2;
    long long res=1;
    int f = -1;
    for(int i=0;i<S1.length()-1;i++){
        if(S1[i] == S1[i+1]){
            if(f == 1){
                res *= 3;
            }else if(f == 0){
                res *= 2;
            }else{
                res *= 6;
            }
            f = 1;
            i++;
        }else{
            if(f == 1){
                res *= 1;
            }else if(f == 0){
                res *= 2;
            }else{
                res *= 3;
            }
            f = 0;
        }
        res %= M;
    }
    if(S1[S1.length()-2] != S1[S1.length()-1] && f == 0){
        res *= 2;
    }
    res %= M;
    cout << res << endl;

    return 0;
} 