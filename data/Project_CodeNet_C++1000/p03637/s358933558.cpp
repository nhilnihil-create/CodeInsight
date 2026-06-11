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
    ll n;cin>>n;
    vector<ll> v(n);
    REP(i,n){
        cin>>v[i];
    }
    ll four=0, two=0, odd=0;
    REP(i,n){
        ll num=v[i];
        if(num%4==0){
            four++;
        }else if(num%2==0){
            two++;
        }else{
            odd++;
        }
    }
    bool is=true;
    if(two==0 && four+1<odd){
        is=false;
    }else if(two!=0 && four<odd){
        is=false;
    }

    if(is){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
