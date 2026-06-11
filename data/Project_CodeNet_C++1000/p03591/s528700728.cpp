#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    string y="YAKI";
    int n=s.size();
    if(s.substr(0,4)==y){cout<<"Yes"<<endl; return 0;}
    cout<<"No"<<endl;
}