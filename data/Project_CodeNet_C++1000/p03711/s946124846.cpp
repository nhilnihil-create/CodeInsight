#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    if(x == 4 || x == 6 || x == 9 || x == 11) x = 100;
    else if(x == 2) x = 101;
    else x = 102;

    if(y == 4 || y == 6 || y == 9 || y == 11) y = 100;
    else if(y == 2) y = 101;
    else y = 102;

    if(x == y) cout << "Yes" << endl;
    else cout << "No" << endl;
}