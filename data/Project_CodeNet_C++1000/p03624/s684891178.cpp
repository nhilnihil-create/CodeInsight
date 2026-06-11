#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        string S; cin >> S;
        vector<int> A(26, 0);
        for (int i = 0; i < S.length(); ++i) {
                A[S[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {

                if (A[i] == 0) {
                        char c = i + 'a';
                        cout << c << endl;
                        exit(0);
                }

        }
        cout << "None" << endl;


}
