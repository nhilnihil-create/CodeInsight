#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b;
    cin >> n >> a >> b;
    long long v[n];
    for(long long i=0; i<n; i++) cin >> v[i];
    sort(v,v+n,greater<long long>());
    long long sum=0;
    for(long long i=0; i<a; i++) sum += v[i];
    long long x,y;
    for(long long i=0; i<n; i++){
        if(v[i]==v[a-1]) {
            x = i;
            break;
        }
    }
    for(long long i=n-1; i>=0; i--){
        if(v[i]==v[a-1]){
            y = i;
            break;
        }
    }
    long long m = y-x+1;
    if(sum == v[a-1]*a){
        cout << v[a-1] << endl;
        long long ans = 0;
        for(long long i = a; i<= min(m,b); i++){
            long long t = 1;
            for(long long j = 1; j<=i; j++){
                t *= m-j+1;
                t /= j;
            }
            ans += t;
        }
        cout << ans << endl;
    }
    else{
        cout << setprecision(20) <<  sum/(double)a << endl;
        long long k = a-x;
        long long ans = 1;
        for(long long i = 1; i<=k; i++){
            ans *= m-i+1;
            ans /= i;
        }
        cout << ans << endl;
    }
    return 0;
}
