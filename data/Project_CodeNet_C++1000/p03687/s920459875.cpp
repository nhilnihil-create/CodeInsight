#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    ll mi = INT32_MAX;
    for (char c = 'a'; c <= 'z'; c++) {
        char p[101];
        strcpy(p, S.c_str());

        int cnt = 0;
        bool others;
        while (1) {
            //if (c == 'r') printf("%s\n", p);
            char *i = p;
            others = false;
            while (*i != '\0') {
                if (*i != c) others = true;
                if (*(i+1) == c) *i = c;
                i++;
            }
            if (others == false) break;
            *(--i) = '\0';
            cnt++;
        }
        //printf("%c: %d\n", c, cnt);
        if (mi > cnt) mi = cnt;
    }
    cout << mi << endl;
}
