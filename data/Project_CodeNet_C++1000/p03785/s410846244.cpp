#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long int C, K;
    cin >> N >> C >> K;

    vector<long long int> T(N);
    for(int n=0; n<N; n++) {
        cin >> T[n];
    }
    
    sort(T.begin(), T.end());
    long long int ans=0;
    long long int cnt=0;
    long long int cur=T[0];
    for(int n=0; n<N; n++) {
        if(T[n]-cur<=K && cnt<C) {
            cnt++;
            if(n==N-1) {
                ans++;
            }
        } else {
            ans++;
            cur=T[n];
            cnt=1;
            if(n==N-1) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
    
}