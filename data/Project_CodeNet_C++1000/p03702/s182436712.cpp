#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
bool check(long long time,long long h[],long long a,long long b,int n){
    long long cnt = 0;
    rep(i,n) cnt+=((max(0LL,h[i]-b*time)+(a-b-1))/(a-b));
    if(cnt<=time) return true;
    return false;
}
int main(){
    int n;
    long long a,b;
    cin >> n >> a >> b;
    long long h[n];
    rep(i,n) cin >> h[i];
    long long left = 0;
    long long right = 1e9+5;
    while((right-left)>1){
        long long middle = (right+left)/2;
        if(check(middle,h,a,b,n)) right = middle;
        else left = middle;
    }
    cout << right << endl;
}