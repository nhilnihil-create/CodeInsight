#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

int main(){
    lli n,m,k;
    string ans="No";
    vector<lli> gvec,kvec;
    lli i,j;
    cin>>n>>m>>k;
    rep(i,0,n+1){
        rep(j,0,m+1){
            if(k==(i*(m-j)+j*(n-i))){
                ans="Yes";
                break;
            }
        }
    }
    cout<<ans<<endl;
}
