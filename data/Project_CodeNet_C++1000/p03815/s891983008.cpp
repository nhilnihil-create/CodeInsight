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
    long long int x,ans=1;
    cin>>x;
    ans+=(x/11)*2-1;
    if((x-11*(x/11))>6){
        ans+=2;
    }
    else{
        if((x-11*(x/11))!=0){
            ans++;
        }
    }
    cout<<ans<<endl;
}
