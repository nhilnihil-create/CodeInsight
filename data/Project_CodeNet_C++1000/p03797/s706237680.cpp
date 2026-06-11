#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)

using namespace std;

int main(){
    long long int n,m,ans=0;
    cin>>n>>m;
    if(2*n<=m){
        m-=2*n;
        ans+=n;
    }
    else{
        ans+=m/2;
        m%=2;
    }
    ans+=m/4;
    cout<<ans<<endl;
}
