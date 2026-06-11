/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;
/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/



int main() {
int K,T;
cin>>K>>T;
pair<int,int> A[T];
int a;
rep3(i,T){
cin>>a;
A[i-1]=make_pair(a,i);
}
sort(A,A+T);
int pre=0,count=0;
rep(i,K){
    if(A[T-1].second==pre){
        if((T>=2)&&(A[T-2].first!=0)){
            pre=A[T-2].second;
            A[T-2]=make_pair(A[T-2].first-1,A[T-2].second);
            sort(A,A+T);
        }
        else{
            count++;
            pre=A[T-1].second;
            A[T-1]=make_pair(A[T-1].first-1,A[T-1].second);
            
        }
    }
    else{
        pre=A[T-1].second;
        A[T-1]=make_pair(A[T-1].first-1,A[T-1].second);
        sort(A,A+T);
        
    }

}
cout<<count<<endl;

return 0;
}