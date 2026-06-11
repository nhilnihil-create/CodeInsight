#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, a = 0;
    string S;
    vector<string> v;
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        cin >> S;
        v.push_back(S);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
        cout << v[i] << endl;
    }
}
