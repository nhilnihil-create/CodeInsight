#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S;
    for (int i = 0; i < H; ++i)
    {
        string temp;
        cin >> temp;
        S.push_back(temp);
    }
    // header
    for (int i = 0; i < W + 2; ++i)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < H; ++i)
    {
        cout << "#";
        cout << S[i];
        cout << "#";
        cout << endl;
    }
    //footer
    for (int i = 0; i < W + 2; ++i)
    {
        cout << "#";
    }
    cout << endl;
}
