#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    long long int r = 1;

    for (int i = 1; i <= n; i++) {
        r *= i;
        r %= 1000000007; 
    }

    
    cout << r;
}