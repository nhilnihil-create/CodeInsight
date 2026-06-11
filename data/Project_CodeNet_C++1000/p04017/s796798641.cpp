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

const int LogN=20;

int main(){
    int n;
    cin>>n;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    
    vector<vector<int>> mv(LogN,vector<int>(n));

    ll l;
    cin>>l;

    for(int i=0;i<n;i++){
        int lb=i;
        int ub=n;
        while(ub-lb>1){
            int mid=(lb+ub)/2;
            if(x[mid]-x[i]<=l) lb=mid;
            else ub=mid;
        }
        mv[0][i]=lb;
    }

    for(int i=0;i+1<LogN;i++){
        for(int j=0;j<n;j++){
            mv[i+1][j]=mv[i][mv[i][j]];
        }
    }

    auto query=[&](int a,int b){
        int d=0;
        for(int i=LogN-1;i>=0;i--){
            int to=mv[i][a];
            if(to<b){
                d+=(1<<i);
                a=mv[i][a];
            }

        }
        return d+1;
    };
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a>b) swap(a,b);
        cout<<query(a,b)<<endl;
    }

    
    return 0;
}
