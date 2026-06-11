#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main(){
  int n;
    cin >> n;
  int a[100000], x;
    for(int i=0; i<n; i++) a[i]=-1;
    for(int i=0; i<n;i++){
      cin >> x;
      a[i] = x-1;
    }
    int cnt=0;
    for(int i=0; i<n;i++){
      if(i==a[a[i]]) cnt += 1;
      //cout << a[a[i]] << i << endl;
    }
    cout << cnt/2 << endl;

}
