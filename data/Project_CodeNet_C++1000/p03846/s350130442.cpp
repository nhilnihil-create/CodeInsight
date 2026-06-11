#include <iostream>
#include <map>

using namespace std;

const long long int MOD=1e9+7;
int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for(int n=0; n<N; n++) {
        int A;
        cin >> A;
        mp[A]++;
    }
    
     bool flag=true;
     long long int cnt=N%2 ? 0 : 1;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        if(N%2==itr->first%2) {
            flag=false;
            break;
        } else {
            if(cnt!=itr->first) {
                flag=false;
                break;
            } else {
                if(cnt==0 && itr->second==1) {
                    cnt += 2;
                    continue;
                } else if(cnt!=0 && itr->second==2) {
                    cnt += 2;
                    continue;
                } else {
                    flag=false;
                    break;
                }
            }
        }
    }
    
    long long int ans;
    if(flag) {
        ans = 1;
        int counter=N/2;
        while(counter!=0) {
            ans *= 2;
            ans %= MOD;
            counter--;
        }
    } else {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
    
}