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
#define allr(v) v.rbegin(), v.rend()
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
const int mod = 1000000007;
const ll INF = 1LL<<50;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return a / GCD(a, b) * b;
}

int main(){

string S;
cin>>S;
bool dream=false,erase=false;
int p=0;
while(p<S.size()){
    if(dream){
        if((p<S.size()-4)&&(S.substr(p,5)=="erase")){
            p+=5;
            dream=false;
            erase=true;
        }
        else if((p<S.size()-1)&&(S.substr(p,2)=="er")){
            p+=2;
            dream=false;

        }
        else if((p<S.size()-4)&&(S.substr(p,5)=="dream")){
            p+=5;
            dream=true;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }

    }
    else if(erase){
        if(S[p]=='r'){
            erase=false;
            p++;
        }
        else if((p<S.size()-4)&&(S.substr(p,5)=="erase")){
            p+=5;
            erase=true;

        }
        else if((p<S.size()-4)&&(S.substr(p,5)=="dream")){
            p+=5;
            erase=false;
            dream=true;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    else{
        if((p<S.size()-4)&&(S.substr(p,5)=="erase")){
            p+=5;
            erase=true;
        }
        else if((p<S.size()-4)&&(S.substr(p,5)=="dream")){
            p+=5;
            dream=true;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }

    }
}
cout<<"YES"<<endl;
return 0;
}