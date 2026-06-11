#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    vector<int> D(10);
    rep(i, K){
        int d; cin >> d;
        D[d] = 1;
    }
    int mi = 100;
    int ma = -1;
    rep(i, 10){
        if(D[i] == 0){
            mi = min(mi, i);
            ma = max(ma, i);
        }
    }

    string s = to_string(N);
    int ss = s.size();
    int p = 100;
    rep(i, ss){
        int a = s[i] - '0';
        if(D[a] == 1){
            p = min(p, i);
        }
    }

    if(p == 100){
        cout << N << endl;
    } else if(s[p] - '0' < ma) {
        for (int i = 0; i < p; i++){
            cout << s[i];
        }
        int x = s[p] - '0';
        for (int i = x+1; i < 10; i++){
            if(D[i] == 0){
                cout << i;
                break;
            }
        }
        for (int i = p+1; i < ss; i++){
            cout << mi;
        }
        cout << endl;
    } else {
        int pf = p;
        for (int i = p-1; i >= 0; i--){
            if(s[i] - '0' != ma){
                p = i;
                break;
            }
        }
        if(p == pf){
            for (int i = 1; i < 10; i++){
                if(D[i] == 0){
                    cout << i;
                    break;
                }
            }
            rep(i, ss){
                cout << mi;
            }
            return 0;
        }
        for (int i = 0; i < p; i++){
            cout << s[i];
        }
        int x = s[p] - '0';
        for (int i = x+1; i < 10; i++){
            if(D[i] == 0){
                cout << i;
                break;
            }
        }
        for (int i = p+1; i < ss; i++){
            cout << mi;
        }
        cout << endl;
    }


    return 0;
}