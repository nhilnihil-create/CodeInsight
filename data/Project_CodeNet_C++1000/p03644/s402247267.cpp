#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int i = 0;
    int multiplier = pow(2, i);

    while(multiplier <= N) {
        i++;
        multiplier = pow(2,i);
    }
    cout << multiplier/2 << endl;
}