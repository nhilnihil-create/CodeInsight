#include <iostream>
#include <map>

using namespace std;

int main() {
    long long int X;
    cin >> X;
    long long int n=0;
    while((n+1)*n/2<X) {
        n++;
    }
    cout << n << endl;

    return 0;
    
}