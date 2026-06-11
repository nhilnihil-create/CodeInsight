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
    lli n,rcnt=0,lcnt=0;                //l=='(', r==')'を数える
    string s;
    lli i,j;
    cin>>n>>s;
    rep(i,0,n){
        if(s[i]=='('){
            lcnt++;
        }
        else{
            if(lcnt>0){
                lcnt--;
            }
            else{
                rcnt++;
            }
        }
    }
//    cout<<"(が"<<rcnt<<"個、)が"<<lcnt<<"個必要"<<endl;
    s=string(rcnt,'(')+s+string(lcnt,')');
    cout<<s<<endl;
}
