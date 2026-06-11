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
    lli n,x,a,sum=0;
    vector<lli> vec;
    lli i,j;
    cin>>n>>x;
    rep(i,0,n){
        cin>>a;
        vec.push_back(a);
    }
    rep(i,1,n){
        if(vec[i]+vec[i-1]>x){
            lli def=vec[i]+vec[i-1]-x;
            sum+=def;
            if(vec[i]>=def){
                vec[i]-=def;
            }
            else{
                def-=vec[i];
                vec[i]=0;
                vec[i-1]-=def;
            }
        }
    }
//    rep(i,0,n){
//        cout<<vec[i]<<" ";
//    }
//    cout<<endl;
    cout<<sum<<endl;
}
