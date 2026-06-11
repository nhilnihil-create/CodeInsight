#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
    int h, w; cin >> h >> w;
    vector<int> alp(26,0);
    rep(i,h*w){
        char c; cin >> c;
        if (c == 'a') alp[0]++;
        else if (c == 'b') alp[1]++;
        else if (c == 'c') alp[2]++;
        else if (c == 'd') alp[3]++;
        else if (c == 'e') alp[4]++;
        else if (c == 'f') alp[5]++;
        else if (c == 'g') alp[6]++;
        else if (c == 'h') alp[7]++;
        else if (c == 'i') alp[8]++;
        else if (c == 'j') alp[9]++;
        else if (c == 'k') alp[10]++;
        else if (c == 'l') alp[11]++;
        else if (c == 'm') alp[12]++;
        else if (c == 'n') alp[13]++;
        else if (c == 'o') alp[14]++;
        else if (c == 'p') alp[15]++;
        else if (c == 'q') alp[16]++;
        else if (c == 'r') alp[17]++;
        else if (c == 's') alp[18]++;
        else if (c == 't') alp[19]++;
        else if (c == 'u') alp[20]++;
        else if (c == 'v') alp[21]++;
        else if (c == 'w') alp[22]++;
        else if (c == 'x') alp[23]++;
        else if (c == 'y') alp[24]++;
        else if (c == 'z') alp[25]++;
    }
    sort(alp.begin(), alp.end());
    bool t = true;
    if (t){
        int hh = h / 2;
        int ww = w / 2;
        int sm = 0;
        int c;
        rep(i,26){
            if (alp[i] >= 4){
                c = alp[i] / 4;
                sm += c;
                alp[i] -= c * 4;
            }
            if (sm >= hh * ww){
                alp[i] += (sm - hh * ww) * 4;
                break;
            }
        }
        if (sm < hh * ww) cout << "No" << endl;
        else{
            int hhh = w % 2 * h / 2;
            int www = h % 2 * w / 2;
            sm = 0;
            rep(i,26){
                if (alp[i] >= 2){
                    c = alp[i] / 2;
                    sm += c;
                    alp[i] -= c * 2;
                }
                if (sm >= hhh + www){
                    alp[i] += (sm - hhh - www) * 2;
                    break;
                }
            }
            if (sm < hhh + www) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}