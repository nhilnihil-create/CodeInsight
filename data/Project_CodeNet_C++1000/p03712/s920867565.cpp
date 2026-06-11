#include <iostream>
using namespace std;

int main() {
    string stra[110];
    int x,y,z;
    cin >> x >> y;
    for(int i=1;i<=x;i++){
        cin >> stra[i];
    }
    z=y+2;
    for(int i=1;i<=z;i++){
        cout << "#";
    }
    cout << endl;
    for(int i=1;i<=x;i++){
        cout << "#" << stra[i] << "#" << endl;
    }
    for(int i=1;i<=z;i++){
        cout << "#";
    }
}