#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;

    string s1, s2; cin >> s1 >> s2;

    for (int i = 0; i < n; i++)
        if (s1[i] == s2[0]) {
            bool g = 1;
            for (int j = i + 1, k = 1; j < n; j++, k++)
                if(s1[j] != s2[k])
                    g = 0;
            if (g){
                cout << i + n;
                return (0);
            }
        }

    cout << 2 * n;
}