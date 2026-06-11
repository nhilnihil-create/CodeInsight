#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x,y;
    cin >> x >> y;
    if(x == 2 || y == 2) cout << "No" << endl;
    else if((x == 4 && (y == 6 || y == 9 || y == 11)) || (x == 6 && (y == 9 || y == 11)) || (x == 9 && y == 11)){
        cout << "Yes" << endl;
    }
    else if((x == 1 && (y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12)) || (x == 3  && (y == 5 || y == 7 || y == 8 || y == 10 || y == 12)) || (x == 5 && (y == 7 || y == 8 || y == 10 || y == 12)) || (x == 7 && (y == 8 || y == 10 || y == 12)) || (x == 8 && (y == 10 || y == 12)) || (x == 10 && y == 12)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
