#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll cnt = 0, i=0;
    for(i=1;i<=n;i++) {
        cnt += i;
        if(cnt >= n) {
            break;
        }
    }
    n -= i;
    vector<int> v;
    v.push_back(i);
    i--;
    while(n > 0) {
        if(n >= i) {
            n -= i;
            v.push_back(i);
            i--;
        }else {
            i--;
        }
    }
    for(int j=0;j<v.size();j++)
        cout << v[j] << endl;
}

