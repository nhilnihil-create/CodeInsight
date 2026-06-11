#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
  long long N,sw= 0,sw2 = 0;
  cin >> N >> sw2;
 long long count = 1;
  froop1(0,N){
    int a;
    cin >> a;
    if(a % 2 != 0){
      sw = 1;
    }
    count *= 2;
  }
  if(sw == 0){
    if(sw2 == 0){
    cout << count << endl;
    }else{
      cout << 0 << endl;
    }
  }else{
   cout << count / 2 << endl; 
  }
}