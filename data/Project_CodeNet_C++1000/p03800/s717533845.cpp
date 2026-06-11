#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(){
    int n;
    cin >> n;
    char s[n+1];
    rep(i,n) cin >> s[i];
    s[n] = s[0];
    int a[4][n+2];
    vector<bool> can(4, false);
    a[0][0] = 0; a[0][1] = 0;
    a[1][0] = 0; a[1][1] = 1;
    a[2][0] = 1; a[2][1] = 0;
    a[3][0] = 1; a[3][1] = 1;
    int c = -1;
    rep(i,4){
        for(int j = 1; j <= n; j++){
            if(s[j] == 'o' && a[i][j] == 0) a[i][j+1] = a[i][j-1];
            else if(s[j] == 'o' && a[i][j] == 1) a[i][j+1] = 1 ^a[i][j-1];
            else if(s[j] == 'x' && a[i][j] == 0) a[i][j+1] = 1 ^a[i][j-1];
            else if(s[j] == 'x' && a[i][j] == 1) a[i][j+1] = a[i][j-1];
         }
         if(a[i][n] == a[i][0] && a[i][n+1] == a[i][1]) c = i;
    }
    if(c == -1) cout << "-1" << endl;
    else{
        rep(i,n){
            if(a[c][i] == 0) cout << "S";
            else cout << "W";
        }
        cout << endl;
    }
    return 0;
}
