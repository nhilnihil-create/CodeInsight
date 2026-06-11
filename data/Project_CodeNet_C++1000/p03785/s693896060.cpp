#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
#include <map>
#include <math.h>

using ll = long long;
using namespace std;

int main(){
    int n, c, k, t;
    cin >> n >> c >> k;
    vector<int> vec;
    rep(i, n){
        int t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    int passe = 1, bus=1, first_time = vec[0];
    reps(i, 1, n){
        if(vec[i]-first_time > k || passe>=c){
                bus++;
                first_time = vec[i];
                passe=1;
            }
        else passe++;
        }
    cout << bus << endl;
}
