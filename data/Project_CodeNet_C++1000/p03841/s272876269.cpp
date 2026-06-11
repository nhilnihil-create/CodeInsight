#include "bits/stdc++.h"
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> x(n);
        for (int i = 0; i < n; i ++) { 
                scanf("%d", &x[i].first);
                x[i].first --;
                x[i].second = i + 1;
        }
        sort(all(x));
        int sp = 0;
        vector<int> ans(n * n, -1);
        for (int i = 0; i < n; i ++) {
                ans[x[i].first] = x[i].second;
                int add = x[i].second - 1;
                while (add --) {
                        if (ans[sp] != -1) add ++;
                        else ans[sp] = x[i].second;
                        sp ++;
                        if (sp > x[i].first) return !puts("No");
                }
        }
        for (int i = 0; i < n; i ++) {
                if (ans[sp] == -1 && sp < x[i].first) return !puts("No");
                int add = n - x[i].second;
                cerr << "sp = " << sp << endl;
                cerr << "add = " << add << endl;
                while (add --) {
                        if (ans[sp] != -1) add ++;
                        else ans[sp] = x[i].second;
                        sp ++;
                }
        }
        puts("Yes");
        for (int i = 0; i < n * n; i ++) cout << ans[i] << (i == n * n - 1 ? '\n' : ' ');
        return 0;   
}

