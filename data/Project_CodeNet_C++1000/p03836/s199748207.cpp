#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    for(int i = 0; i < ty - sy; i++) cout << 'U';
    for(int i = 0; i < tx - sx; i++) cout << 'R';

    for(int i = 0; i < ty - sy; i++) cout << 'D';
    for(int i = 0; i < tx - sx; i++) cout << 'L';

    cout << 'L';
    for(int i = 0; i < ty - sy + 1; i++) cout << 'U';
    for(int i = 0; i < tx - sx + 1; i++) cout << 'R';
    cout << 'D';

    cout << 'R';
    for(int i = 0; i < ty - sy + 1; i++) cout << 'D';
    for(int i = 0; i < tx - sx + 1; i++) cout << 'L';
    cout << 'U' << endl;
}