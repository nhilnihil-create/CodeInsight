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
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;
string ts[]={"maerd","remaerd","esare","resare"};
bool equal(string t, string s, int i){
    int m=t.length();
    for(int j=0;j<m;j++){
        if(t[j]!=s[i+j]) return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int n=s.length();
    bool f=true;
    reverse(s.begin(), s.end());
    for(int i=0;i<n;){
        bool g=false;
        int m=0;
        for(int j=0;j<4;j++){
            string t=ts[j];
            m=t.length();
            if(i+m>n) continue;
            if(equal(t,s,i)){
                g=true;
                break;
            }
        }
        if(g){
            i+=m;
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
        //cout<<i<<endl;
    }
    cout<<"YES"<<endl;
}