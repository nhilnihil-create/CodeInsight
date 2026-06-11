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

lli gcd(lli a,lli b){
    if(b>a){
        swap(a,b);
    }
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    lli n,k,a,b;
    vector<lli> vec,big;
    lli i,j;
    cin>>n>>k;
    rep(i,0,n){
        cin>>a;
        if(a>=k){
            big.push_back(a-k);
        }
        vec.push_back(a);
        if(i==0){
            b=a;
        }
        b=gcd(a,b);
    }
    if(big.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        rep(i,0,big.size()){
            if(big[i]%b==0){
                cout<<"POSSIBLE"<<endl;
                break;
            }
            else if(i==big.size()-1){
                cout<<"IMPOSSIBLE"<<endl;
            }
        }
    }
}
