#include <iostream>

using namespace std;

const long long int MOD=1e9+7;

int main() {
    int N;
    cin >> N;
    string s1, s2;
    cin >> s1 >> s2;
    
    int pre=0;
    long long int ans;
    for(int i=0; i<s1.size(); i++) {
        if(i+1<s1.size() && s1[i]==s1[i+1]) {
            if(pre==0) {
                ans = 6;
            } else if(pre==1) {
                ans *= 2;
            } else {
                ans *= 3;
            }
            pre=2;
            i++;
        } else {
            if(pre==0) {
                ans = 3;
            } else if(pre==1) {
                ans *= 2;
            } else {
                ans *= 1;
            }
            pre=1;
        }
        ans %= MOD;
    }
    
    cout << ans << endl;

    return 0;
    
}