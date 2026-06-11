#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> p(N+2);
    for(int i=1; i<=N; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        if(p[i] == i) {
            swap(p[i], p[i+1]);
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
