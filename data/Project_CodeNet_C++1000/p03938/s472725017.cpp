#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    ll n;
    cin>>n;
    ll p[n];
    ll a[n+1]={},b[n+1]={};
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    reverse(p,p+n);
    for(int i=0;i<n;i++){
        a[p[i]]+=i+1;
        b[0]+=i+1,b[p[i]-1]-=i+1;
    }
    for(int i=0;i<n;i++){
        a[i+1] += a[i];
        b[i+1] += b[i];
        //cout << a[i] << " ";
    }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << b[i] << " ";
    // }
    //cout << endl;
    for(int i=0;i<n;i++){
        a[i] += i+1;
        b[i] += n-i;
    }
    
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;


}