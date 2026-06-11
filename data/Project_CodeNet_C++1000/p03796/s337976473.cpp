#include<bits/stdc++.h>


using namespace std;
const long long mod=1000000007;
#define max 10005
int main(){
    long n;
    cin >> n;
    long long f=1;
    for(int i=1; i<=n; i++){
      f = f*i;
      f = f%mod;
    }
    cout << f << endl;
    return 0;
}