#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
typedef long long ll;
typedef long double ld;
int main(){
    int n,a;cin>>n;
    vector<int> v(9),list={399,799,1199,1599,1999,2399,2799,3199,4800};
    REP(i,n){
        cin>>a;
        REP(j,9){
            if(a<=list[j]){
                v[j]++;
                break;
            }
        }
    }
    int color=0,mi,ma;
    REP(i,8){
        if(v[i]>0){
            color++;
        }
    }
    mi=max(1,color);
    ma=color+v[8];
    cout<<mi<<" "<<ma<<endl;
    return 0;
}
