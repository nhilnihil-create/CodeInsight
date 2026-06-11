#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007
typedef long long ll;

int main() {
    int n;cin>>n;
    int max=0,x=0;

    rep(i,n){
        int a,b;cin>>a>>b;
        if(a>max){
            max=a;x=b;
        }
    }
    cout<<max+x<<endl;

}
