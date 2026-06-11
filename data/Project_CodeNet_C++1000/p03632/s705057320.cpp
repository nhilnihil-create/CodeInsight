#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a<=c){
        if(c<=b){
            if(b<=d) cout<<b-c<<endl;
            else cout<<d-c<<endl;
        }
        else cout<<0<<endl;
    }
    else{
        if(a<=d){
            if(d<=b) cout<<d-a<<endl;
            else cout<<b-a<<endl;
        }
        else cout<<0<<endl;
    }
}