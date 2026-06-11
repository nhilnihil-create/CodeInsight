#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, M;
    int a, b;
    cin >> N >> M;

    vector<int> city(N, 0);

    rep(i, M)
    {
        cin >> a >> b;
        city.at(a-1)++;
        city.at(b-1)++;
    }
    rep(i, N){
        cout << city.at(i) << endl;
    }
    
    return 0;
}