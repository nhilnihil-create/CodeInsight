#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long int;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v[i] = P(a,i);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i%2 != v[i].second%2) ans++;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}
