#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N; cin >> N;
    int c2 = 0, c4 = 0;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        if(a % 4 == 0) c4++;
        else if(a % 2 == 0) c2++;
    }
    int len;
    if(c2 == 0) len = 2 * c4 + 1;
    else len = 2 * c4 + c2;
    if(len >= N) cout << "Yes" << endl;
    else cout << "No" << endl;
}
