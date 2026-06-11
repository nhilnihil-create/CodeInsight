#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    int score = 0;
    rep(i,N){
        if(S[i] == 'I'){
            score++;
        }
        else{
            score--;
        }
        ans = max(score,ans);
    }
    cout << ans;
}
