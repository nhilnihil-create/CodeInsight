#include <iostream>
using namespace std;

int main(void) {
    
    int kid;
    int sum = 0;

    cin >> kid;

    for (int i = 0; i <= kid; i++) {
        sum += i;
    }

    cout << sum << endl; 

    return 0;
}