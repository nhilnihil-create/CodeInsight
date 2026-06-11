#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A;
    unsigned long long answer = 0;
    for (int i = 0; i < 3 * N; ++i)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.rbegin(), A.rend());
    for (int i = 0; i < N; ++i)
    {
        answer += A[2 * i + 1];
    }
    cout << answer << endl;
}