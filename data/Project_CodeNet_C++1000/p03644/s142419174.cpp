#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 1;
    while (true)
    {
        if (pow(2, count) > N)
        {
            break;
        }
        ++count;
    }
    cout << pow(2, count - 1) << endl;
}