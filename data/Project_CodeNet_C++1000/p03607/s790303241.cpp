#include <bits/stdc++.h>
 #define rep(i,n) for(long long i=0;i<n;i++)
 using namespace std;
  int main(){
      int n;
      cin >> n;
      vector<long long> a(n);
      rep(i,n){
          cin >> a[i];
      }
      int num=0;
      int r=0;
      sort(a.begin(),a.end());
      rep(i,n-1){
          if(a[i]!=a[i+1])continue;
          if(r==a[i]){r=0; continue;}
          r = a[i];
          num++;
      }
    cout << n-(num*2) << endl;
    return 0;
  }