#include <bits/stdc++.h>
using namespace std;
int main() {
    string N;
    int K;
    cin >> N >> K;
    vector<char> D(K);
    unordered_map<char, int> mp;
    for (int i = 0; i < K; i++) {
        cin >> D.at(i);
        mp[D.at(i)] = 1;
    }
    char m = '-', mm = '-';
    for (char i = '0'; i <= '9'; i++) {
        if (mp[i] == 0) {
            if (m == '-') {
                m = i;
            }
            else {
                mm = i;
            }
            if (m != '-') {
                if (m != '0' || mm != '-') {
                    break;
                }
            }
        }
    }
    bool KRAG = false;
    for (int i = 1; i <= (int) N.size(); i++) {
        int j = (int) N.size() - i;
        int check = 0;
        if (KRAG) {
            int memo = N.at(j) - '0';
            for (int k = (int) N.size() - 1; k > j; k--) {
                N.at(k) = m;
            }
            if (memo == 9) {
                N.at(j) = m;
                continue;
            }
            memo++;
            N.at(j) = memo + 0x30;
            //cout << j  <<"    "<<N.at(j)<<endl;
        }
        char memo2;
        memo2 = N.at(j);
        for (char k = N.at(j); k <= '9'; k++) {
            if (mp[k] == 0) {
                N.at(j) = k;
                check = 1;
                break;
            }
        }
        if (check == 0) {
            N.at(j) = m;
            KRAG = true;
        }
        else {
            KRAG = false;
        }
        if (memo2 != N.at(j)) {
            for (int k = (int) N.size() - 1; k > j; k--) {
                N.at(k) = m;
            }
        }
    }
    if (KRAG) {
        for (int k = (int) N.size() - 1; k > 0; k--) {
            N.at(k) = m;
        }
        if (m != '0') {
            N = m + N;
        }
        else {
            N = mm + N;
        }
    }
    cout << N << endl;
}