#include <iostream>
using namespace std;

int main()
{
    int N, l, r, answer = 0;
    cin >> N;

    for (int count = 0; count < N; count++)
    {
        cin >> l >> r;
        answer += r - l + 1;
    }

    cout << answer << endl;
}