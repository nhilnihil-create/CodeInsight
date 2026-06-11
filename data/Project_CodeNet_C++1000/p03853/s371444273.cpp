#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e9 
typedef long long ll;
typedef long double ld;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> v(h,vector<char>(w));
    REP(i,h)REP(j,w)cin>>v[i][j];
    REP(i,h){
        REP(j,w){
            cout<<v[i][j];
        }
        cout<<endl;
        REP(j,w){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}
