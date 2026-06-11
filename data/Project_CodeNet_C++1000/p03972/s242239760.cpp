#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int main() {
    int W, H;
    vector<P> v;
    cin >> W >> H;
    for(int i=0;i<W+H;i++){
        int p; cin >> p;
        v.push_back(P(p, i));
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    ll w = W+1, h = H+1;
    for(int i=0;i<W+H;i++){
        ll p = v[i].first;
        if(v[i].second < W){
            w--;
            ans += h*p;
        }else{
            h--;
            ans += w*p;
        }
    }
    cout << ans << endl;
	return 0;
}