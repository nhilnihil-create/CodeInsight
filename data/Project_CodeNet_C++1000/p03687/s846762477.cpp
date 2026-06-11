#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    int N = S.size();
    int res = N - 1;

    auto Ok = [&](string T) {
        return set<char>(T.begin(), T.end()).size() == 1;
    };

    for (char x = 'a'; x <= 'z'; x++) {
        auto A = S;
            
        int steps = 0;

        while(true) {
            if (Ok(A))
                break;

            string nA = A;
            nA.pop_back();

            //cerr << x << " " << A << " " << nA << "\n";

            for (int i = 0; i < A.size() - 1; i++)
                if (A[i] == x || A[i + 1] == x)
                    nA[i] = x;
                else
                    nA[i] = A[i];

            A = nA;
            steps++;
        }

        res = min(res, steps);
    }    

    cout << res << "\n";

    return 0;
}
