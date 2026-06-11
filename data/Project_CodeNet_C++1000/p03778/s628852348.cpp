#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    ll w,a,b;
    cin>>w>>a>>b;
    ll left,right;
    if(b>a){
        left = a;
        right = b;
    }
    else{
        left = b;
        right = a;
    }

    if(left+w>right) cout<<"0"<<endl;
    else cout<<right-(left+w)<<endl;
    return 0;
}