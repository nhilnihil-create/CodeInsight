#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>

using namespace std;
const long long INF = 1LL << 60;
typedef long long int lli;

int main()
{
    // Input numbers
    int a, b, h;
    cin >> a >> b >> h;

    cout << (int)((a+b)*h/2) << endl;
    return 0;
}