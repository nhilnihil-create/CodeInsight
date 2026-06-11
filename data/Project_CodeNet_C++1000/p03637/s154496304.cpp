#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n;
    cin>>n;
    int one=0;
    int two=0;
    int four=0;
    for(int i=0;i<n;i++){
        ll a; cin>>a;
        if(a%2==1){
            one++;
        }else if(a%4!=0){
            two++;
        }else{
            four++;
        }
    }
    bool f=false;
    if(four<=one-2){
        f=false;
    }else if(four==one-1){
        if(two==0){
            f=true;
        }
    }else{
        f=true;
    }
    if(f){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    

}