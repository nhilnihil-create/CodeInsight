#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size()){
        cout<<"GREATER"<<endl;
        return 0;
    }
    else if(a.size()<b.size()){
        cout<<"LESS"<<endl;
        return 0;
    }
    else{
        rep(i,a.size()){
            if(a[i]>b[i]){
                cout<<"GREATER"<<endl;
                return 0;
            }else if(a[i]<b[i]){
                cout<<"LESS"<<endl;
                return 0;
            }
        }
        cout<<"EQUAL"<<endl;
    }
    return 0;
}