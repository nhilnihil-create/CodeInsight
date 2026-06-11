#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    //const double PI=3.141592653589793238;


    int N, K, X, Y, count=0, i=1;
    cin >> N >> K >> X >> Y;

    while(i <= N)
    {
        if(i<=K) count += X;
        else count += Y;
        i++;
    }


    cout << count << endl;

    return 0;
}