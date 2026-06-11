//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007


signed main(){
    int N;
    cin>>N;

    int ans=LLONG_MAX;
    for(int i=1;i<sqrt(N)+1;i++){
        if(N%i==0){
            int n1=N/i;
            int n2=i;
            int keta1=0;
            int keta2=0;
            while(n1!=0){
                keta1++;
                n1/=10;
            }
            while(n2!=0){
                keta2++;
                n2/=10;
            }
            ans=min(ans,max(keta1,keta2));
        }
    }

    cout<<ans<<endl;
}
