#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int x,a,b;
    cin >> x >> a >> b;
    
    if(abs(x - a) < abs(x - b)){
        cout << "A";
    } else{
        cout << "B";
    }
    return 0;
}