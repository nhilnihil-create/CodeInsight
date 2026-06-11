#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int lx = abs(tx-sx);
    int ly = abs(ty-sy);

    for(int i=0; i<lx; i++){
        cout << "R";
    }
    for(int i=0; i<ly; i++){
        cout << "U";
    }
    for(int i=0; i<lx; i++){
        cout << "L";
    }
    for(int i=0; i<ly; i++){
        cout << "D";
    }

    cout << "D";
    for(int i=0; i<lx+1; i++){
        cout << "R";
    }
    for(int i=0; i<ly+1; i++){
        cout << "U";
    }
    cout << "L";
    cout << "U";
    for(int i=0; i<lx+1; i++){
        cout << "L";
    }
    for(int i=0; i<ly+1; i++){
        cout << "D";
    }
    cout << "R" << endl;;

    return 0;
}
