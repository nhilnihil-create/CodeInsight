#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());
    if (s[n-1] == 'g'){
        cout << n / 2 << endl;
        return 0;
    } else if (s[0] == 'p') {
        cout << n / 2 - n << endl;
        return 0;
    }
    int i, l = 0, r = n;
    while (1) {
        i = (l + r) / 2;
        if (s[i-1] == 'g' && s[i] == 'p') break;
        if (s[i] == 'g') l = i;
        else             r = i;
    }
    cout << n / 2 - (n - i) << endl;
    return 0;
}