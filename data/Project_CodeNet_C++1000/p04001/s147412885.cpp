#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string S;
    cin >> S;
    int N = S.size();

    int64_t ans = 0;
    for(int bit=0; bit<(1<<N-1); bit++) {
        int last = 0;
        for(int i=0; i<N; i++) {
            if(bit >> i & 1) {
                ans += stoll(S.substr(last, i-last+1));
                last = i+1;
            }
        }
        ans += stoll(S.substr(last, N - last));
    }

    cout << ans << endl;
    return 0;
}
