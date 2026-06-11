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
#define repr4(i,s,n) for(ll i = (n);i>=(s);i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
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


int main(){
ll Q,H,S,D,N;
cin>>Q>>H>>S>>D>>N;
N*=4;
ll ans=0;
if((D<=S*2)&&(D<=H*4)&&(D<=Q*8)){
    ans+=(N/8)*D;
    N=N%8;
    if((S<=H*2)&&(S<=Q*4)){
        ans+=S*(N/4);
    }
    else if(H*2<=Q*4){
        ans+=H*(N/2);
    }
    else{
        ans+=Q*N;
    }


}
else if((S*2<=H*4)&&(S*2<=Q*8)){
    ans+=(N/4)*S;
}
else if(H*4<=Q*8){
    ans+=(N/2)*H;

}
else{
    ans+=N*Q;
}
cout<<ans<<endl;

return 0;
}