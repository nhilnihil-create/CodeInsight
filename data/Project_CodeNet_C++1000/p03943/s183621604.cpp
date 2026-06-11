#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    vector<int>a(3);
    rep(i,3){
        cin>>a.at(i);
    }
    sort(a.begin(),a.end());
    int A=a.at(0)+a.at(1);
    int B=a.at(2);
    if(A==B){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
