#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) {
        cin >> x;
        --x;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int j = a[i];
        if (i < j && a[j] == i) {
            ++ans;
        }
    }

    cout << ans << endl;
}