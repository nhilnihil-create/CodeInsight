#include <iostream>

using namespace std;

int main() {
    int N;
    long long int T;
    cin >> N >> T;
    long long int st=0;
    long long int et=0;
    long long int ans=0;
    for(int n=0; n<N; n++) {
        long long int t;
        cin >> t;
        
        if(et>=t) {
            et = t+T;
        } else {
            ans += et-st;
            st = t;
            et = t+T;
        }
    }
    
    ans += et-st;
    cout << ans << endl;

    return 0;
    
}