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
    long long n,l,t;
    cin>>n>>l>>t;
    vector<long long> x(n),w(n),tmp(n),res(n);
    for(int i=0;i<n;++i)cin>>x[i]>>w[i];
    for(int i=0;i<n;++i)x[i] = x[i] * n + i;
    l *= n;
    t *= n;
    for(int i=0;i<n;++i){
        if(w[i]==1)res[i] = (x[i] + t)%l;
        else res[i] = (x[i] - t)%l;
        res[i] = (res[i] + l) % l;
    }
    long long b = res[0];
    for(int i=0;i<n;++i){
        res[i] -= b;
        res[i] %= l;
        res[i] += l;
        res[i] %= l;
    }
    sort(res.begin(),res.end());
    for(int i=0;i<n;++i)res[i] = (res[i]+b)%l;
    if(w[0]==1){
        long long k = 0;
        for(int i=1;i<n;++i)if(w[i]==2){
            k += 2 * (t / l);
            long long tt = t % l;
            if(2 * tt >= x[i] - x[0])k++;
            if(2 * tt >= l + x[i] - x[0])k++;
        }
        k %= n;
        long long b = res[0];
        for(int i=0;i<n;++i){
            cout<<res[(i-k+n)%n]/n<<endl;
        }
    }
    else{
        long long k = 0;
        for(int i=1;i<n;++i)if(w[i]==1){
            k += 2 * (t / l);
            long long tt = t % l;
            if(2 * tt >= l - x[i] + x[0])k++;
            if(2 * tt >= 2 * l - x[i] + x[0])k++;
        }
        k %= n;
        for(int i=0;i<n;++i){
            cout<<res[(i+k)%n]/n<<endl;
        }
    }
    return 0;
}