#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cnt = 0;
    int max_val = 0;
    for (char c: s) {
        if (c == 'I') cnt++;
        else cnt--;
        if (max_val < cnt) max_val = cnt;
    }
    cout << max_val << '\n';
    return 0;
}