#include <iostream>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A,B;
    cin >> A >> B;
    if(A%3 == 0 || B%3 == 0 || (A+B)%3 == 0) fin("Possible");
    else fin("Impossible");
    return 0;
}