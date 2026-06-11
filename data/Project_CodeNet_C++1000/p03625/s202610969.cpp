#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    int N;
    cin >> N;
    map<ll, int> MP;
    rep(i, 0, N){
        ll tmp;
        cin >> tmp;
        MP[tmp]++;
    }
    ll ans = 0;
    vector<ll>A(N);
    ll index = 0;
    for(auto & s : MP){
        if(s.second>=2){
            A[index] = s.first;
            index++;
        }
    }
    sort(A.begin(), A.end(), greater<ll>());
    
    if (MP[A[0]]>=4){
        ans = A[0] * A[0];
    } else {
       ans = A[0] * A[1];
    }
    cout << ans << endl;
    return 0;
}
