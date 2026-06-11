#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long a[n];
    long long com=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        com = __gcd(com,a[i]);
        if(a[i]==k){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    sort(a,a+n);
    if(a[n-1]<k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if(k%com==0){
        cout <<  "POSSIBLE" << endl;
        return 0;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
}