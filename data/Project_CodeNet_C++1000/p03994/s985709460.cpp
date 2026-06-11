#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < s.size(); i++){
        int tmp = (26 - (s[i] - 'a')) % 26;
        if (tmp <= k) s[i] = 'a', k -= tmp;
    }
    if (k > 0) s.back() = (char)((s.back() - 'a' + k) % 26 + 'a');
    cout << s << endl;
}