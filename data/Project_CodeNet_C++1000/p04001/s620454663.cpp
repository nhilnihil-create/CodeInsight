#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll by_bit_brute_force(const string &s)
{
    int n = s.size()-1;
    ll ans = 0, k = 1, sum;
    for(int i=0; i < (1 << n); ++i){
        sum = 0;
        k = 1;
        for(int j=0;j<n;++j){
            if((i >> j) & 1){
                ans += (sum + (s[n-j] - '0') * k);
                k = 1;
                sum = 0;
            }
            else{
                sum += (s[n-j] - '0') * k;
                k *= 10;
            }
        }
        ans += (sum + (s[0] - '0') * k);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << by_bit_brute_force(s) << endl;
}
