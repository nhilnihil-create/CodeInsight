#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    string S;
    int N;
    cin >> N >> S;

    int ans = 0, x = 0;
    rep(i, N){
        if(S[i] == 'I') x++;
        else x--;
        ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}