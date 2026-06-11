#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    int n,r=0;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    r+=a[n-1]+b[0];
    cout<<r<<endl;
  return 0;
}