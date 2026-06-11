#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=50005;
const int NAX=1005;
const long MOD=(long)(1e9+7);

Int N,M,K;
Int X,Y,Z;
Int perform(Int x){
    return (x*(x+1))/2LL;
}
vector<Int> A;


int main()
{
    cin>>N>>M>>K>>X;
    cout<<max((N*M),(X*K));
     
}
