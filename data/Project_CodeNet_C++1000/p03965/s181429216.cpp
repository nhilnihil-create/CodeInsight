#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int G = 0, P = 0, ans = 0;
    for (auto c: S){
        if (c == 'g'){
            if (P + 1 <= G){
                ans += 1;
                P += 1;
            }else{
                G += 1;
            }
        }else{
            if (P + 1 <= G){
                P += 1;
            }else{
                ans -= 1;
                G += 1;
            }
        }
    }
    cout << ans << endl;
}