#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,str,end) for(ll i=(ll)(str); i<(ll)(end); i++)

int main(){
    string a,b;
    cin>>a>>b;
    if(a==b){cout<<"EQUAL"<<endl;return 0;}
    else if(a.size()<b.size()){cout<<"LESS"<<endl;return 0;}
    else if(a.size()>b.size()){cout<<"GREATER"<<endl;return 0;}
    else if(a.size()==b.size()){
        rep(i, 0, a.size() ){
            int N=a[i]-'0';
            int M=b[i]-'0';
            if(N>M)
            {cout<<"GREATER"<<endl;return 0;}
            else if(N<M)
            {cout<<"LESS"<<endl;return 0;}
        }
    }
    return 0;
}