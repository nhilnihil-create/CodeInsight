#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    string S;
    int x = 0;
    int ans = 0;

    cin >> N;
    cin >> S;

    for(int i = 0; i < N; i++){
        if(S[i] == 'I'){
            x += 1;
        } 
        else{
            x -= 1;
        }

        if(x >= ans){
            ans = x;
        }
    }

    cout << ans << endl;

    return 0;
}