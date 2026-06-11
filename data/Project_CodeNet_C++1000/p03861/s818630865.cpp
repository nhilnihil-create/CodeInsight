#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

int main()
{
    long long a, b, x;
    cin >> a >> b >> x;
    if(a!=0) cout << (b / x) - ((a - 1) / x) << endl;
    else cout << (b / x) + 1 << endl;
    return 0;
}
