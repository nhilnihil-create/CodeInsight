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
    ll a,b,c;
    cin>>a>>b>>c;
    ll cnt=0;
    while(a%2!=1&&b%2!=1&&c%2!=1){
        if(a==b&&b==c){
            cnt=-1;
            break;
        }else{
            ll n,m,l;
            n=a/2, m=b/2, l=c/2;
            a=m+l;
            b=n+l;
            c=n+m;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
