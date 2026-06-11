
#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A != 7 && B != 7 && C != 7)
    {
        cout << "NO";
    }
    else
    {
        if ((A == 5 && B == 5) || (A == 5 && C == 5) || (B == 5 && C == 5))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}