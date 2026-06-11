#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

typedef long long ll;

int main(){
  int n;
  cin >> n;
  int not24 = 0;
  int by2 = 0;
  int by4 = 0;
  rep(i,n){
    int x;
    cin >> x;
    if(x%4 == 0){
      by4 ++;
    }else if(x%2 == 0){
      by2 ++;
    }else{
      not24 ++;
    }
  }//i
  if(not24 == 0){
    cout << "Yes" << endl;
    return 0;
  }
  if(by4 >= not24-1){
    if(by4 == not24-1 && by2 > 0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }else{
    cout << "No" << endl;
  }
}