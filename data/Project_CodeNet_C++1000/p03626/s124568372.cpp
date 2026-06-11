#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    int i = 0;
    int temp = 0;
    ll ans = 1;
    ll waru = 1000000007;
    if(n == 1){
        cout << 3 << endl;
        return 0;
    }
    while(i < n){
        if(i == 0){
            if(s1.at(i) == s1.at(i+1)){
                ans *= 6;
                temp = 1;
                i += 2;
            }else{
                ans *= 3;
                temp = 0;
                ++i;
            }
        }else if(i == n-1){
            if(temp == 0){
                ans *= 2;
            }
            ++i;
        }else{
            if(s1.at(i) == s1.at(i+1)){
                if(temp){
                    ans *= 3;
                }else{
                    temp = 1;
                    ans *= 2;
                }
                i += 2;
            }else{
                if(temp){
                    temp = 0;
                }else{
                    ans *= 2;
                }
                ++i;
            }
        }
        ans %= waru;
    }
    cout << ans << endl;
    return 0;
}