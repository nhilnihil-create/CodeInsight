#include <bits/stdc++.h>
using namespace std;

int	main()
{
    string S;
    cin >> S;
    int size = S.size();
    int len;
    for (len = size - 2; len > 0; len -= 2) {
        bool is_feasible = true;
        for (int j = 0; j < len / 2; ++j) {
            if (S.at(j) != S.at(len / 2 + j)) {
                is_feasible = false;
                break;
            }
        }
        if (is_feasible)
            break;
    }
    cout << len << endl;
}
