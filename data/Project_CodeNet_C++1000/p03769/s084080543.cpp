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
#define int long long
signed main(){
    ll n;
    cin >> n;
    vector<int> v;
    vector<int> p;
    int s = 100;
    while(n!=0){
        if(v.size()==0){
            v.push_back(1);
            p.push_back(s);
            s--;
            n-=1;
            continue;
        }   
        int c = 1;
        int k = 0; 
        for(int i=v.size()-1;i>=0;i--){
            if(c+v[i]<=n){
                c += v[i];
            }else{
                k = i+1;
                break;
            }
        }
        vector<int> a;
        vector<int> b;
        rep(i,v.size()){
            if(i==k){
                b.push_back(s);
                s--;
                a.push_back(c);
            }
            a.push_back(v[i]);
            b.push_back(p[i]);
        }
        if(k==v.size()){
            a.push_back(c);
            b.push_back(s);
            s--;
        }
        v = a;
        p = b;
        n -= c;
    }
    cout << 100 + v.size() << endl;
    rep(i,100){
        cout << i+1 << " ";
    }
    rep(i,p.size()){
        cout << p[i];
        if(i!=p.size()-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}