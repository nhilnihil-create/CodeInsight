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
    lli n,a,sum=0;
    vector<lli> vec;
    lli i,j;
    cin>>n;
    rep(i,0,n){
        cin>>a;
        vec.push_back(a);
    }
    rep(i,0,n){
        sum+=vec[i]/2;
        if(i<n-1){
            vec[i]%=2;
            if(vec[i]==1&&vec[i+1]>0){
                sum++;
                vec[i]--;
                vec[i+1]--;
            }
        }
    }
    cout<<sum<<endl;
}
