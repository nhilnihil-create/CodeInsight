#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int T, A;
    long long t_min = 1, a_min = 1, ans;
    for (int i = 0; i < N; i++) {
    	cin >> T >> A;

    	long long n = max((t_min - 1) / T, (a_min - 1) / A) + 1;
        t_min = T * n;
        a_min = A * n;
    }

    ans = t_min + a_min;

    cout << ans << endl;

    return 0;
}