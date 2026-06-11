#include <iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << fixed<<setprecision(0)<<k * pow(k - 1, n - 1) << endl;
}