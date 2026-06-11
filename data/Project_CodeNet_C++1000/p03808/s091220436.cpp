#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL N;
    cin >> N;
    vector<LL> a(N+1), d(N);
    LL sum = 0;
    bool f = true;
    for(int i = 0;i < N;i++){
        cin >> a[i];
        sum += a[i];
    }
    a[N] = a[0];
    for(int i = 0;i < N;i++)  d[i] = a[i+1]-a[i];
    LL ns = N*(N+1)/2;
    LL m = sum/ns;
    if(sum%ns != 0) f = false;
    LL ksum = 0;
    for(int i = 0;i < N;i++){
        ksum += (m-d[i])/N;
        if(m-d[i] < 0 || (m-d[i])%N != 0) f = false;
    }
    if(ksum != m)   f = false;
    if(f)   cout << "YES" << endl;
    else    cout << "NO" << endl;
}