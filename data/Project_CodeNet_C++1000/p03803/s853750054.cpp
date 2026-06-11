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
    int a,b; cin>>a>>b;
    if(a==b)cout<<"Draw"<<endl;
    else if(a==1)cout<<"Alice"<<endl;
    else if(b==1)cout<<"Bob"<<endl;
    else if(a<b)cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
}



