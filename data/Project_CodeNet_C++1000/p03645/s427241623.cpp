#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> one;
    set<int> enu;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        if(a == 1) one.push_back(b);
        if(b == N) enu.insert(a);
    }
    bool is = false;
    int len = (int)one.size();
    rep(i, len){
        if(enu.count(one[i]) == 1) is = true;
    }
    if(is) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}