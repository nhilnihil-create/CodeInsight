#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;


int main(int argc, char const *argv[]) {
    int n;cin>>n;
    vector<long long> x(n);
    for(int i=0;i<n;++i)cin>>x[i];
    long long m,k;cin>>m>>k;
    vector<int> a(m),b(n-1),res(n-1);
    for(int i=0;i<m;++i){
        cin>>a[i];
        a[i]-=2;
    }
    for(int i=0;i<n-1;++i){
        b[i] = i;
        res[i] = i;
    }
    for(int i=0;i<m;++i){
        int tmp = b[a[i]];
        b[a[i]] = b[a[i]+1];
        b[a[i]+1] = tmp;
    }
    while(k>0){
        if(k%2==1){
            vector<int> tmp(n-1);
            for(int i=0;i<n-1;++i)tmp[i] = res[b[i]];
            for(int i=0;i<n-1;++i)res[i] = tmp[i];
        }
        vector<int> tmp(n-1);
        for(int i=0;i<n-1;++i)tmp[i] = b[b[i]];
        for(int i=0;i<n-1;++i)b[i] = tmp[i];
        k /= 2;
    }
    long long su = x[0];
    cout<<su<<endl;
    for(int i=0;i<n-1;++i){
        su += x[res[i]+1]-x[res[i]];
        cout<<su<<endl;
    }
    return 0;
}