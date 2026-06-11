#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int a[3];
    int x = 0, y = 0, z = 0;
    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 3; i++){
        if(a[i] == 5) x++;
        if(a[i] == 7) y++;
    }

    if(x == 2 && y == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}