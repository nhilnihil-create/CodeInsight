#include <bits/stdc++.h>
using namespace std;

//初見×
//2次元配列でなく1次元配列+string
int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> picture(H);
    for (int i = 0; i < H; i++)
    {
        cin >> picture.at(i);
    }

    cout << string(W + 2, '#') << endl;
    for (int i = 0; i < H; i++)
    {
        cout << '#' << picture.at(i) << '#' << endl;
    }
    cout << string(W + 2, '#') << endl;
}
