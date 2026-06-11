#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    ll length[3];
    bool flag = false;
    rep(i, 3) {
        cin >> length[i];
        if(length[i]%2==0)
            flag = true;
    }
    sort(length, length + 3);
    if(flag)
        cout << 0 << endl;
    else
        cout << length[0] * length[1] << endl;
    return 0;
}