#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const int MOD=1e9+7;
int main()
{
    ll n; cin>>n;
    n++;
    int d;
    int ct=0;
    bool c[41]={};
    for(int i=0; i<41; i++){
        if(n<(1ll<<i)){
            d=i;
            break;
        }
        if(n&(1ll<<i)){
            c[i]=1; ct++;
        }
    }
    vector<int> ans;
    int ct1=ct;
    for(int i=0; i<d-1; i++){
        if(c[i]){
            ct1--; ans.push_back(d-1+ct1);
        }
        ans.push_back(i+1);
    }
    for(int i=0; i<d-1; i++) ans.push_back(i+1);
    for(int i=0; i<ct-1; i++) ans.push_back(d+i);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i<(int)ans.size()-1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}