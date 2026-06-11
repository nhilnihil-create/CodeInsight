#include <bits/stdc++.h>
 
using namespace std;


int solve2(string x) {
    string ret = x;
    while (1) {
        int n = ret.size();
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (ret.at(i - 1) == 'S' && ret.at(i) == 'T') {
                flag = false;
                ret = ret.substr(0, i - 1) + ret.substr(i + 1);          
                break;
            }   
        }
        if (flag) {
            break;
        }
    }
    return ret.size();
}



int solve(string x) {
    int ret = 0;
    int n = x.size();
    int cnt_s = 0;
    int cnt_t = 0;
    for (int i = 0; i < n; i++) {
        if (x.at(i) == 'S') {
            if (i > 0 && x.at(i - 1) == 'T') {
                // ret += abs(cnt_s - cnt_t);
                if (cnt_s < cnt_t) {
                    ret += cnt_t - cnt_s;
                    cnt_s = 0;
                }
                else {
                    cnt_s -= cnt_t;
                }
                cnt_s++;
                cnt_t = 0;
            }
            else {
                cnt_s++;
            }
        }
        else {
            cnt_t++;
        }
    }
    ret += abs(cnt_s - cnt_t);
    return ret;    
}


void test() {
    for (int n = 1; n <= 6; n++) {
        for (int bit = 0; bit < (1 << n); bit++) {
            string x;
            for (int i = 0; i < n; i++) {
                if (bit & (1 << i)) {
                    x += "S";
                }
                else {
                    x += "T";
                }
            }
            if (solve(x) != solve2(x)) {
                cout << "x = " << x << endl;
                cout << "solve(x) = " << solve(x) << endl;
                cout << "solve2(x) = " << solve2(x) << endl;
                break; 
            }
        }
    }
}


int main() {
    string x;
    cin >> x;
    cout << solve(x) << endl;
    // cout << solve2(x) << endl;
    // test();
    return 0;
}