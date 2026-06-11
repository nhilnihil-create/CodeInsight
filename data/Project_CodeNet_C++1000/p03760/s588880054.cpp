#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e10
typedef long long ll;
typedef long double ld;
int main(){
    string o,e;
    cin>>o>>e;
    ll s_o=SIZE(o), s_e=SIZE(e);
    ll length=s_o+s_e;
    vector<char> v(length);
    REP(i,s_o){
        v[i*2]=o[i];
    }
    REP(i,s_e){
        v[i*2+1]=e[i];
    }
    REP(i,length){
        cout<<v[i];
    }
    cout<<endl;
    return 0;
}
