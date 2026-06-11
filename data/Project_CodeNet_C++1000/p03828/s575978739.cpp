#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;

vector<ll> prime_list(ll n){
    vector<ll> list;
    FOR(i,2,n){
        if(i==2){list.push_back(i);continue;}
        if(i%2==0)continue;
        bool is=true;
        FOR(j,2,sqrt(i)){
            if(i%j==0){
                is=false;
                break;
            }else{
                is=true;
            }
        }
        if(is){
            list.push_back(i);
        }
    }
    return list;
}

int main(){
    ll n,cnt=0;
    cin>>n;
    vector<ll> primes=prime_list(n);
    vector<ll> v(1001,1);
    FOR(i,2,n){
        ll p;
        REP(j,SIZE(primes)){
            p=primes[j];
            if(i%p==0){
                ll num=i;
                while(num%p==0){
                    num/=p;
                    v[p]++;
                }
            }
            if(p>i)break;
        }
    }
    ll prd=1;
    REP(i, 1001){
        prd*=v[i];
        prd%=1000000007;
    }
    cout<< prd <<endl;
    return 0;
}
