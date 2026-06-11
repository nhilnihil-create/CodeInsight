#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >>a>>b>>c>>d;
    
    int ab = a * b;
    int cd = c * d;
    
    if (ab > cd) {
        cout << ab <<endl;
    } else {
        cout << cd << endl;
    }
}
