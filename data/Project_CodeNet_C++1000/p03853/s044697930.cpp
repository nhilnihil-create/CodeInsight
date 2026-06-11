#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    char pixel_org[H][W];

    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            cin >> pixel_org[i][j];
    
    cout << endl;

    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            cout << pixel_org[i][j];
        }
        cout << endl;

        for(int j=0; j<W; j++)
        {
            cout << pixel_org[i][j];
        }
        cout << endl;
    }
    return 0;
}