#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    string w;
    cin >> w;
    // sort(w.begin(), w.end());
    int flag = 1;
    rep(i, w.size()){
        int cnt = 0;
        rep(j, w.size()){
            if(w[i] == w[j]){
                cnt++;
            }
        }
        if(cnt%2!=0){flag= 0;}
    }
    if(flag) cout << "Yes" <<endl;
    else cout << "No" <<endl;

    return 0;
}