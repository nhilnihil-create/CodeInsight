#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    long long h, w; cin >> h >> w;
    long long ans=numeric_limits<long long>::max();
    for(int i=1; i<=(h+1)/2; ++i){
        long long a=w*i;
        long long r=h-i;
        long long b=r*(w/2), c=r*(w-w/2);
        long long mx=max(a, max(b, c)), mn=min(a, min(b, c));
        ans=min(ans, mx-mn);
        if(h-i*2>0){
            long long a=i*w, b=i*w, c=(h-i*2)*w;
            long long mx=max(a, max(b, c)), mn=min(a, min(b, c));
            ans=min(ans, mx-mn);
        }
    }
    for(int i=1; i<=(w+1)/2; ++i){
        long long a=h*i;
        long long r=w-i;
        long long b=r*(h/2), c=r*(h-h/2);
        long long mx=max(a, max(b, c)), mn=min(a, min(b, c));
        ans=min(ans, mx-mn);
        if(w-i*2>0){
            long long a=i*h, b=i*h, c=(w-i*2)*h;
            long long mx=max(a, max(b, c)), mn=min(a, min(b, c));
            ans=min(ans, mx-mn);
        }
    }
    cout << ans << endl;
    return 0;
}
