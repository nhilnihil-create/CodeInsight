
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int x, y; cin >> x >> y;
    if (x == 2 || y == 2) cout << "No"  << endl;
    else {
        if ((x == 4 || x == 6 || x == 9 || x == 11)
         && (y != 4 && y != 6 && y != 9 && y != 11))
                          cout << "No"  << endl;
        else              cout << "Yes" << endl;
    }
    return 0;
}
