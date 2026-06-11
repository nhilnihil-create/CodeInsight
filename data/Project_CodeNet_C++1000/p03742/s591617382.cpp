#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long a,b;
    cin >> a >> b;
    if(abs(a - b) <= 1){
        cout << "Brown" << endl;
    }
    else{
        cout << "Alice" << endl;
    }
}