#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define SORT(s) sort((s).begin(),(s).end())

struct Box{
    bool red;
    int count;
};


int main(){
    int N; cin >> N;
    int M; cin >> M;

    vector<Box> b(N);
    REP(i,N){
        b.at(i).red = false;
        b.at(i).count = 1;
    }
    b.at(0).red = true;
    REP(i,M){
        int x; cin >> x;
        int y; cin >> y;
        x -= 1;
        y -= 1;
        b.at(x).count -= 1;
        b.at(y).count += 1;
        if (b.at(x).red) {
            b.at(y).red = true;
        }
        if (b.at(x).count == 0){
            b.at(x).red = false;
        }
    }
    int ans = 0;
    for(auto v : b){
        if (v.red){
            ans += 1;
        }
    }
    cout << ans << endl;
}
