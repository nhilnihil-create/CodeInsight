#include <iostream>
#include <algorithm>
#include <climits>


using namespace std;


using ull = unsigned long long;


int main()
{
    ull N, T;
    cin >> N >> T;

    ull prev, ans, stop;
    ans = 0;
    cin >> prev;
    stop = prev + T;
    for (ull i = 0; i < N - 1; i++) {
        ull now;
        cin >> now;

        if (stop > now) {
            ans += (now - prev);
        } else {
            ans += T;
        }
        prev = now;
        stop = now + T;
    }
    cout << ans + T << endl;
}
