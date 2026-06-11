#include <bits/stdc++.h>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;
 
int main() {
    int n;
  cin >> n;
    vector<ll> a(n);
    ll l1=0,l2=0;
    int c1=0,c2=0;
    rep(i,n)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    rep(i,n)
    {
        if(a[i]==a[i+1] && l1==0){
            l1=a[i];
            i++;
        }
        else if(a[i]==a[i+1] && l1!=0){
            l2=a[i];
            break;
        }
    }
    cout << l1*l2 << endl;
}