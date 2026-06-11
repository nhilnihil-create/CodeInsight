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
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999999;



int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int now=0;
    bool tate=true;
    ll ans=1;
    while(now<n){
        if(now==0){
            if(s[now]==t[now]){
                ans*=3;
                tate=true;
                now++;
            }else{
                ans*=6;
                tate=false;
                now+=2;
            }
            continue;
        }
        if(s[now]==t[now]){
            if(tate){
                ans*=2;
            }else{
                ans*=1;
            }
            now++;
            tate=true;
        }else{
            if(tate){
                ans*=2;
            }else{
                ans*=3;
            }
            now+=2;
            tate=false;
        }
        ans%=MOD;
    }
    cout<<ans<<endl;
}