#include <iostream>

using namespace std;

int main() {
    int X = 0, t = 0;
    int result = 0;

    cin >> X >> t;

    
    result = X - t;
    if(result > 0) {
        cout << result << endl;
    } else {
        result = 0;
        cout << result << endl;
    }
}
