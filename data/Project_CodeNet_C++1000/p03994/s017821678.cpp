//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<climits>

/*
#include<boost/multiprecision/cpp_long long.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Blong long = mp::cpp_long long;
*/

using namespace std;

#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

int main(){
    string s;
    int K;
    cin>>s>>K;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]!='a'&&'z'-s[i]+1<=K){
            K-='z'-s[i]+1;
            s[i]='a';
        }
    }
    K%=26;
    while(K>0){
        s[s.size()-1]++;
        K--;
    }
    cout<<s<<endl;
}
