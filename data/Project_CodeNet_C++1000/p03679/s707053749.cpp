//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll x,a,b; cin>>x>>a>>b;
    if(b-a<=0)cout<<"delicious"<<endl;
    else if(b-a<=x)cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;
}



