#include <iostream>
#include <vector>
#include <algorithm>
// #include <map>
// #include <set>
// #include <cmath>
// #include <string>

using namespace std;
typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    int N;
    ull A, B;
    cin >> N >> A >> B;
 
    vector<ull> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    ull ans = 0;
    for (int i = 0; i < N-1; i++) {
        ans += min((X[i+1] - X[i]) * A, B);
    }

    cout << ans << endl;
    
    return 0;
}
