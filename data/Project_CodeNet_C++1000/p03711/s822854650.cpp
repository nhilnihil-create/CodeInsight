#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int x,y;
    cin>>x>>y;
    int a=0,b=0;
    vector<int>s1{1,3,5,7,8,10,12};
    vector<int>s2{4,6,9,11};
    rep(i,s1.size()){
        if(x==s1[i]){
            a=1;
        }
        if(y==s1[i]){
            b=1;
        }
    }
    rep(i,s2.size()){
        if(x==s2[i]){
            a=2;
        }
        if(y==s2[i]){
            b=2;
        }
    }
    cout<<(a==b?"Yes":"No")<<endl;
}