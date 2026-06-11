#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
    string S;
    cin >> S;
    int ans = 0;
    int N = S.size();
    int g=0,p=0;
    rep(i,N){
        if(S[i] == 'p'){
            p++;
        }
    }
    ans = N / 2 - p;
    cout << ans << endl;
}
