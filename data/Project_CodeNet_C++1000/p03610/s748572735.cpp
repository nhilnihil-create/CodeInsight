#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int mojisuu=0;
    mojisuu = s.size();

    string ans;

    for(int i=0; i<mojisuu; i = i+2)
    {
        ans += s.at(i);
    }

    cout << ans << endl;

}