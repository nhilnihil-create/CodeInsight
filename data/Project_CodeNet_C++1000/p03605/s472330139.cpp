#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    
    while (N) {
        if (N % 10 == 9) {
            cout << "Yes" << endl;
            return 0;
        }
        N /= 10;
    }
    cout << "No" << endl;
}
