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
    string a,b,c; cin>>a>>b>>c;
    if(a[a.size()-1]!=b[0]){
        cout<<"NO"<<endl;
    }
    else if(b[b.size()-1]!=c[0]){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}



