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
    string str;
    cin>>str;
    int size=SIZE(str);
    vector<char> v={'N', 'S', 'W', 'E'};
    vector<int> cnt(4);
    REP(i,size){
        char c;
        c=str[i];
        REP(j,4){
            if(c==v[j])cnt[j]++;
        }
    }
    int n=cnt[0], s=cnt[1], w=cnt[2], e=cnt[3];
    bool isv, ish;
    if(n*n+s*s==0)isv=true;
    else if(n*s==0)isv=false;
    else isv=true;
    if(w*w+e*e==0)ish=true;
    else if(w*e==0)ish=false;
    else ish=true;
    string ans=(isv&&ish)?"Yes":"No";
    cout<<ans<<endl;
    return 0;
}
