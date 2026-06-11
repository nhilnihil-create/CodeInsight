#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;

int main(){
    int n;cin>>n;
    vector<int> v(100003);
    while(n--){
        int a;cin>>a;
        v[a]++;
        v[a+1]++;
        v[a+2]++;
    }
    cout<<MAX(v)<<endl;
    return 0;
}
