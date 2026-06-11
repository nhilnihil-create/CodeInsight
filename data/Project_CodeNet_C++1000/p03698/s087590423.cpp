#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        string S;
        cin >> S;
        map<int, int> m;
        for (int i = 0; i < S.length(); ++i) {
                m[S[i] - 'a']++;
        }
        for (auto i : m) {
                if (i.second != 1) {
                        cout << "no" << endl;
                        exit(0);
                }
        }
        cout << "yes" << endl;



}
