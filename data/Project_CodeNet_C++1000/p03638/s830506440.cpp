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
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll h,w,n;cin>>h>>w>>n;
    vector<ll> a(n);
    REP(i,n){
        cin>>a[i];
    }
    vector<ll> v1;
    vector<vector<ll>> v2(h,vector<ll>(w));
    REP(i,n){
        ll num=a[i];
        REP(j,num){
            v1.push_back(i+1);
        }
    }
    ll size=SIZE(v1), b=0;
    
        REP(i,h){
            REP(j,w){
                v2[i][j]=v1[b];
                b++;
            }
            if(i%2==1){
                sort(ALL(v2[i]),greater<>());
            }
        }
    
    REP(i,h){
        REP(j,w){
            cout<<v2[i][j];
            if(j==w-1){
                cout<<endl;
            }else{
                cout<<" ";
            }
        }
    }
    return 0;
}
