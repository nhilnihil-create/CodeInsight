#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    int n; cin>>n;
    vector<int> a(n);
    int x, y, sum = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum += a[i];
    }

    x = sum/n;
    y = (sum+n-1)/n;
    ll x1 = 0, y1 = 0;
    for(int i = 0; i<n; i++){
        x1 += (x-a[i])*(x-a[i]);
        y1 += (y-a[i])*(y-a[i]);
    }

    cout<<min(x1, y1);
    return 0;
}