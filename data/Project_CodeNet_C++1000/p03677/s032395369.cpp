#include<iostream>
#include<iomanip>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i],a[i]--;

    vector<vector<int>> ls(m);
    vector<vector<int>> rs(m);
    for(int i=0;i+1<n;i++){
        ls[a[i]].push_back(i);
        rs[a[i+1]].push_back(i);
    }

    int mid = 0;
    ll sc = 0;
    for(int i=0;i+1<n;i++){
        if(a[i]<a[i+1]){
            sc += a[i+1]-a[i];
        }
        else{
            if(a[i]!=0) mid++;
            sc += a[i+1]+1;
        }
    }
    ll res = sc;

    auto dist=[&](int l,int r){
        if(l<r) return r-l;
        else return m-l+r;
    };
    
    for(auto p:rs[0]){
        sc += dist(a[p],a[p+1])-1;
        mid--;
    }
    for(auto v:ls[0]){
        mid++;
        sc++;
    }
    
    for(int i=1;i<m;i++){
        sc -= mid;
        res = min(res,sc);
        
        for(auto p:rs[i]){
            sc += dist(a[p],a[p+1])-1;
            mid--;
        }
        for(auto v:ls[i]){
            mid++;
            sc++;
        }
    }

    cout<<res<<endl;

    return 0;
}
