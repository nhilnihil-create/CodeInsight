#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    int a,b; cin>>a>>b;
    if(a%3==0||b%3==0||(a+b)%3==0)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
