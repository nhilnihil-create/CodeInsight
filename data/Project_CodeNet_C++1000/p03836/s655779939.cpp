#include<iostream>
using namespace std;
int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    for (int i = sy + 1; i <= ty; i++) cout << 'U';
    for (int i = sx + 1; i <= tx; i++) cout << 'R';
    for (int i = ty - 1; i >= sy; i--) cout << 'D';
    for (int i = tx - 1; i >= sx; i--) cout << 'L';
    cout << 'L';
    for (int i = sy; i <= ty; i++) cout << 'U';
    for (int i = sx; i <= tx; i++) cout << 'R';
    cout << "DR";
    for (int i = ty; i >= sy; i--) cout << 'D';
    for (int i = tx; i >= sx; i--) cout << 'L';
    cout << 'U';
    return 0;
}