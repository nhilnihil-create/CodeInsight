#include <iostream>

using namespace std;

int main(){
    int x;
    int t;
    cin >> x >> t;
    if(x > t){
        cout << x - t << endl;
    }
    else{
        cout << "0" << endl;
    }
}