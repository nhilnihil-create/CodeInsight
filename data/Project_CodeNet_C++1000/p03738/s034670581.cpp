#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    int a = A.length(); int b = B.length();
    if (a > b) {
        cout << "GREATER\n";
        return 0;
    }
    else if (a < b) {
        cout << "LESS\n";
        return 0;
    }
    for (int i=0; i<a; i++) {
        if (A[i] > B[i]) {
            cout << "GREATER\n";
            return 0;
        }
        else if (A[i] < B[i]) {
            cout << "LESS\n";
            return 0;
        }
    }
    cout << "EQUAL\n";
    
    return 0;
}