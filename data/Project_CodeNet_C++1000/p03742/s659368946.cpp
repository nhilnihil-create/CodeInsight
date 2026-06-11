#include <iostream>
using namespace std;

typedef long long lint;

int main(){
    lint X,Y;
    cin >> X >> Y;
    if(Y<=X+1 && Y>=X-1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
    
    return 0;
}