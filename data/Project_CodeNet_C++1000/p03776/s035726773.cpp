#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int mod = 1000000007;
 
 
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    vector<ll> v(N);
    for(ll i=0;i<N;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),cmp);
    ll sum=0;
    for(ll i=0;i<A;i++){
        sum+=v[i];
    }
    long double r = (double)sum/A;
    printf("%.10Lf\n",r);
    ll com[51][51]={0};
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }
    if(v[0]==v[A-1]){
        ll num=0;
        for(ll i=0;i<N;i++){
            if(v[i]==v[0]){
                num++;
            }
        }
        ll res=0;
        for(ll j=A;j<=B;j++){
            res += com[num][j];
        }
        cout<<res<<endl;
        return 0;
    }else{
        double _min = v[A-1];
        ll num_toA=0;
        ll num=0;
        for(ll i=0;i<A;i++){
            if(_min == v[i])num_toA++;
        }
        for(ll i=0;i<N;i++){
            if(_min == v[i])num++;
        }
        cout<<com[num][num_toA]<<endl;
    }

}