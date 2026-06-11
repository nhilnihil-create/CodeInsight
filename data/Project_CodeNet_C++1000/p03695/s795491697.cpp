#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
    ll N;
    cin>>N;
    vector<int> v(9);
    rep(i,N){
        ll n;
        cin>>n;
        if(1<=n&&n<=399){
          v[0]=1;
        }
        else if(400<=n&&n<=799){
          v[1]=1;
        }
        else if(800<=n&&n<=1199){
          v[2]=1;
        }
        else if(1200<=n&&n<=1599){
          v[3]=1;
        }
        else if(1600<=n&&n<=1999){
          v[4]=1;
        }
        else if(2000<=n&&n<=2399){
          v[5]=1;
        }
        else if(2400<=n&&n<=2799){
          v[6]=1;
        }
        else if(2800<=n&&n<=3199){
          v[7]=1;
        }
        else{
          v[8]++;
        }
    }
    int m,M;
    M=accumulate(v.begin(), v.end(),0);
    m=M-v[8];
    if(m == 0){
      m = 1;
    }
    cout << m <<' '<< M << endl;
}
