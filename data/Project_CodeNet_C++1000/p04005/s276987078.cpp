#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    long long N[3];
    cin >> N[0] >> N[1] >> N[2];

    if (N[0] % 2 == 0 || N[1] % 2 == 0 || N[2] % 2 == 0)
    {
        cout << 0 << endl;
    }else
    {
        sort(N, N + 3);
        cout << N[0] * N[1] << endl;
    }
    
    return 0;
}