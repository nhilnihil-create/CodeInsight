#include <iostream>
using namespace std;

int main()
{
    int K, S;
    cin >> K >> S;
    int answer = 0;
    for (int x = 0; x < K + 1; ++x)
    {
        for (int y = 0; y < K + 1; ++y)
        {
            if (S - x - y <= K && S - x - y >= 0)
            {
                ++answer;
            }
        }
    }
    cout << answer << endl;
}