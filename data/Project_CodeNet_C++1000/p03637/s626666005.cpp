#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n;
    cin>>n;
    int p=0,q=0,r=0;
    rep(i,n){
        int a;
        cin>>a;
        if(a%4==0)p++;
        else if(a%2==0)q++;
        else r++;
    }
    if(q==0){
        if(r<=p+1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    if(r<=p)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}