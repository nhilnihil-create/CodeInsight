#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    int K;
    int step = 0;
    int ball;
    cin >> N;
    cin >> K;
    rep(i, N){
        cin >> ball;
        if (ball > K - ball){
            step += (K - ball) * 2;
        }
        else
        {
            step += ball * 2;
        }
        
    }
    cout << step << endl;
}