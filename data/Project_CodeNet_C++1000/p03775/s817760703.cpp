#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int l;
    long stocks = 1000;

    for (long long i = 1; i*i <= n; i++) {
        if (n % i != 0) continue;
        string s = to_string(n/i);
        if (s.size() < stocks) stocks = s.size();
        
    }

    cout << stocks << endl;

}