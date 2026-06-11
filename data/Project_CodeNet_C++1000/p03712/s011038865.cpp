#include<bits/stdc++.h>
#include <vector>
#define endl '\n';
using namespace std;

int main()
{
    string s[100];
    int h, w; cin >> h >> w;
    for (int i = 0; i < h; ++i)
        cin >> s[i];
    for (int i = 1; i <= w + 2; ++i)
        cout << "#";
    cout << "\n";
    for (int i = 0; i < h; ++i) {   
        cout << "#" << s[i] << "#" << "\n";
    }
    for (int i = 1; i <= w + 2; ++i)
        cout << "#";
    return 0;
}