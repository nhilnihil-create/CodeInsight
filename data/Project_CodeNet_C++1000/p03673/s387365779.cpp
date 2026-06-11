#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    vector<int> b(n);
    int m;
    if(n%2==0)m = n/2;
    else m = n/2;
    rep(i,n){
        if(i%2==0)b[m+i/2] = a[i];
        else b[m-i/2-1] = a[i];
    }
    if(n % 2 == 1)reverse(all(b));
    rep(i,n){
        if(i!=n-1)cout << b[i] << " ";
        else cout << b[i] << endl;
    }
    return 0;
}