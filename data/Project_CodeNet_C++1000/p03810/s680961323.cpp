#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

bool dfs(vector<ll>&a){
    int n = a.size();
    vector<ll>p(n),q(n);
    ll sm = 0;
    for(int i=0;i<n;i++){
        sm += a[i];
        if(i==0){
            p[i] = a[i];
        }else{
            p[i] = gcd(p[i-1],a[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            q[i] = a[i];
        }else{
            q[i] = gcd(q[i+1],a[i]);
        }
    }
    bool flag = 0;
    rep(i,n){
        if(a[i]==1)continue;
        if(i==0){
            ll g = gcd(q[1],a[0]-1);
            ll x = (sm-1)/g;
            if((x-n)%2==0){
                if(g!=1){
                    vector<ll>b(n);
                    rep(j,n){
                        if(j!=i)b[j] = a[j]/g;
                        else b[j] = (a[j]-1)/g;
                    }
                    if(!dfs(b)){
                        flag = 1;
                    }
                }else{
                    flag = 1;
                }
            }
        }else if(i==n-1){
            ll g = gcd(p[n-2],a[n-1]-1);
            ll x = (sm-1)/g;
            if((x-n)%2==0){
                if(g!=1){
                    vector<ll>b(n);
                    rep(j,n){
                        if(j!=i)b[j] = a[j]/g;
                        else b[j] = (a[j]-1)/g;
                        
                    }
                    if(!dfs(b)){
                        flag = 1;
                    }
                }else{
                    flag = 1;
                }
            }
        }else{
            ll g = gcd(p[i-1],a[i]-1);
            g = gcd(g,q[i+1]);
            ll x = (sm-1)/g;
            
            if((x-n)%2==0){
                if(g!=1){
                    vector<ll>b(n);
                    rep(j,n){
                        if(j!=i)b[j] = a[j]/g;
                        else b[j] = (a[j]-1)/g;
                    }
                    if(!dfs(b)){
                        flag = 1;
                    }
                }else{
                    flag = 1;
                }
            }
        }
    }
    return flag;
}

int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    if(dfs(a)){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    return 0;
}