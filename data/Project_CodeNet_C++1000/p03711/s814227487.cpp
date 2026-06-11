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
    int x,y; cin>>x>>y;
    bool xx=false,yy=false;
    vector<int>a={1,3,5,7,8,10,12};
    rep(i,7){
        if(a[i]==x)xx=true;
        if(a[i]==y)yy=true;
    }
    if(xx&&yy){
        cout<<"Yes"<<endl;
        return 0;
    }
    xx=false;yy=false;
    vector<int>b={4,6,9,12};
    rep(i,4){
        if(b[i]==x)xx=true;
        if(b[i]==y)yy=true;
    }
    if(xx&&yy){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(x==2&&y==2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


}



