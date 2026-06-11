#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll sx, sy, tx, ty;
    cin>>sx>>sy>>tx>>ty;
    rep(i, tx-sx) cout<<"R";
    rep(i, ty-sy) cout<<"U";
    rep(i, tx-sx) cout<<"L";
    rep(i, ty-sy) cout<<"D";
    cout<<"D";
    rep(i, tx-sx+1) cout<<"R";
    rep(i, ty-sy+1) cout<<"U";
    cout<<"L";
    cout<<"U";
    rep(i, tx-sx+1) cout<<"L";
    rep(i, ty-sy+1) cout<<"D";
    cout<<"R"<<endl;
    return 0;
}
