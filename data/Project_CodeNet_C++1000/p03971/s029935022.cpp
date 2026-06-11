#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    int qual = 0;
    int rankOvers = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' && qual < a+b) {
            cout << "Yes\n";
            qual++;
        }
        else if (s[i] == 'b' && qual < a+b && rankOvers <= b) {
            cout << "Yes\n";
            qual++;
            rankOvers++;
        }
        else cout << "No\n";
    }
    return 0;
}
