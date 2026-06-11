#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
long long n,a[200010],one[200010],two[200010],par,mx;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        ll tmp;
        cin>>tmp;
        a[tmp]=i;
    }
    one[1] = 5e+8;
    two[1] = 5e+8;
    for(int i=2; i<=n; i++){
        if (a[i]>a[i-1]){
            one[i] = one[i-1] + 1 + (a[i]-a[i-1]);
            two[i] = two[i-1] - 1;
        }
        else if (a[i] < a[i-1]){
            one[i] = one[i-1] + 1;
            two[i] = two[i-1] - 1 + (a[i]-a[i-1]);
        }
    }
    for(int i=1; i<n; i++) cout<<one[i]<<' ';
    cout<<one[n]<<endl;
    for(int i=1; i<n; i++) cout<<two[i]<<' ';
    cout<<two[n]<<endl;
    return 0;
}