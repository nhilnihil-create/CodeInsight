#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    int x,a,b; cin>>x>>a>>b;
    if(a>=b)cout<<"delicious"<<endl;
    else if(b-a<=x)cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;
}
