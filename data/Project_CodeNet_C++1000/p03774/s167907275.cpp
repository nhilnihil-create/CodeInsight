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
    int N,M;
    int a[100],b[100],c[100],d[100];
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<M;i++){
        cin>>c[i]>>d[i];
    }
    for(int i=0;i<N;i++){
        int minn=LLONG_MAX,mini=-1;
        for(int j=0;j<M;j++){
            int l=abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(l<minn){
                minn=l;
                mini=j+1;
            }
        }
        cout<<mini<<endl;
    }
}
