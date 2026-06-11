#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    string S,ans;

    cin >> S;

    for(int i = 0; i<S.length(); i += 2){
        ans += S[i];
    }

    cout << ans << endl;

}
