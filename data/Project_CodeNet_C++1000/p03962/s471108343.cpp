#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 3;
    if (a == b){
        ans --;
    }
    if (b == c){
        ans --;
    }
    if (c == a){
        ans --;
    }
    if (a == b && b == c){
        ans ++;
    }

    cout << ans << endl;
}