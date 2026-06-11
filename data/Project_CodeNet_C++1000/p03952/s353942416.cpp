#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;cin >> n >> x;
  if(n==2){
    if(x==2){
      cout << "Yes" << endl;
      for(int i=1;i<=3;i++){
        cout << i << endl;
      }
    }
    else{
      cout << "No" << endl;
    }
    return 0;
  }
  if(x==1||x==2*n-1){
    cout << "No" << endl;
    return 0;
  }
  if(n==x){
    cout << "Yes" << endl;
    for(int i=1;i<=2*n-1;i++){
      cout << i << endl;
    }
    return 0;
  }
  int cnt=1;
  cout << "Yes" << endl;
  if(x!=2){
    for(int i=1;i<=2*n-1;i++){
      if(i<n-1){
        if(cnt==x-2){
          cnt+=4;
        }
        cout << cnt << endl;
        cnt++;
      }
      else if(i==n-1){
        cout << x-1 << endl;
      }
      else if(i==n){
        cout << x << endl;
      }
      else if(i==n+1){
        cout << x+1 << endl;
      }
      else if(i==n+2){
        cout << x-2 << endl;
      }
      else{
        if(cnt==x-2){
          cnt+=4;
        }
        cout << cnt << endl;
        cnt++;
      }
    }
    return 0;
  }
  for(int i=1;i<=2*n-1;i++){
    if(i<n-1){
      if(cnt==x-1){
        cnt+=4;
      }
      cout << cnt << endl;
      cnt++;
    }
    else if(i==n-1){
      cout << x+1 << endl;
    }
    else if(i==n){
      cout << x << endl;
    }
    else if(i==n+1){
      cout << x-1 << endl;
    }
    else if(i==n+2){
      cout << x+2 << endl;
    }
    else{
      if(cnt==x-1){
        cnt+=4;
      }
      cout << cnt << endl;
      cnt++;
    }
  }
}