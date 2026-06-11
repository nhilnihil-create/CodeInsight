#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, char> P;
ll w, h, xvec, yvec, res;
vector<P> road;
int main(void){
    // Your code here!
    cin >> w >> h;
    for (ll i = 0; i < w; i++) {
        cin >> xvec;
        road.push_back(P(xvec, 'x'));
    }
    for (ll i = 0; i < h; i++) {
        cin >> yvec;
        road.push_back(P(yvec, 'y'));
    }
    sort(road.begin(), road.end());
    for (ll i = 0; i < road.size(); i++){
        P Q = road[i];
        if (Q.second == 'x'){
            res += Q.first * (h + 1);
            w--;
        } else {
            res += Q.first * (w + 1);
            h--;
        }
    }
    cout << res << endl;
}
