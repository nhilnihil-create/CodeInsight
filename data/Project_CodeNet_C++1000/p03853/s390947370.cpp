#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> data(h, vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> data.at(i).at(j);
        }
    }

    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(j==w-1) cout << data.at(i).at(j) << endl;
            else cout << data.at(i).at(j);
        }
        for (int j = 0; j < w; j++)
        {
            if(j==w-1) cout << data.at(i).at(j) << endl;
            else cout << data.at(i).at(j);
        }
        
    }
    return 0;
}