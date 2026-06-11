#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    ll n;
    cin >> n;
    rep(i, n + 1){
        ll sum = ((ll)i) * (i + 1) / 2;
        if(sum < n){
            continue;
        }
        rep(j, i){
            if(sum - n == j + 1)
                continue;
            cout << j + 1 << endl;
        }
        break;
    }
    return 0;
}
