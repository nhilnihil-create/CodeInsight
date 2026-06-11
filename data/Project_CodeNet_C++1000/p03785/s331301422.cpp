#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,c,k;
    cin >> n >> c >> k;
    long long t[n];
    for(int i=0;i<n;i++) cin >> t[i];
    sort(t,t+n);
    long long res=0,i=0;
    while(i<n){
        long long j=i;
        while(i<n&&i-j<c&&t[i]<=t[j]+k){
            i++;
        }
        res++;
    }
    cout << res << endl;
}