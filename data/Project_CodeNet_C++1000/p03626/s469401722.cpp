#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
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
    ll n;cin>>n;
    vector<char> s1(n),s2(n);
    REP(i,n)cin>>s1[i];
    REP(i,n)cin>>s2[i];
    ll prd=1,type;
    
    REP(i,n){
        if(s1[i]==s2[i]){
            if(i==0){
                prd*=3;
            }else{
                type==0?prd*=2:prd*=1;
            }
            type=0;
        }else{
            if(i==0){
                prd*=6;
            }else{
                type==0?prd*=2:prd*=3;
            }
            type=1;
            i++;
        }
        prd=prd%1000000007;
    }
    cout<<prd<<endl;
    return 0;
}
