#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli ans,scnt=0;
    string x;
    lli i,j;
    cin>>x;
    ans=x.size();
    rep(i,0,x.size()){
        if(x[i]=='S'){
            scnt++;
        }
        else if(scnt!=0){
            if(x[i]=='T'){
                scnt--;
                ans-=2;
            }
        }
    }
    cout<<ans<<endl;
}
