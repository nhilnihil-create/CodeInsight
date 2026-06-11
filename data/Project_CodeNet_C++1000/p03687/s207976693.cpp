#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

string s;

int main() {
    cin >> s;
    vector<int> ansalp(26, 0);
    for(int i = 0; i < 26; ++i) {
        char check = i + 'a';
        bool flg = false;
        int cnt = 0;
        for(int j = 0; j < (int)s.length(); ++j) {
            if(s.at(j) != check) {
                flg = true;
                break;
            }
        }
        if(flg) cnt++;
        string sch = s;
        while(flg) {
            string nsch;
            for(int j = 0; j < (int)(sch.length()-1); ++j) {
                if(sch.at(j) == check || sch.at(j+1) == check) {
                    nsch.push_back(check);
                }else {
                    nsch.push_back(sch.at(j));
                }
            }
            bool fflg = true;
            for(int j = 0; j < (int)nsch.length(); ++j) {
                if(nsch.at(j) != check) {
                    fflg = false;
                    break;
                }
            }
            if(fflg) {
                flg = false;
                break;
            }else {
                sch = nsch;
                cnt++;
            }
        }
        ansalp.at(i) = cnt;
    }

    sort(ansalp.begin(), ansalp.end());
    cout << ansalp.at(0) << endl;
}