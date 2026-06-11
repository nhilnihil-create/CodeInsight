#include <iostream>
#include <map>

using namespace std;

const long long int MOD=1e9+7;

int main() {
    int N;
    cin >> N;
    map<int, long long int> mp;
    for(int n=2; n<=N; n++) {
        int tmp=n;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
            while(tmp%itr->first==0) {
                itr->second++;
                tmp /= itr->first;
            }
        }
        if(tmp>1) {
            mp[tmp]++;
        }
    }
    
    long long int ans=1;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        ans *= (itr->second+1);
        ans %= MOD;
    }
    
    cout << ans << endl;


    return 0;
    
}