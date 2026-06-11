#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  while(true){ 
   int N = S.size();
   if(N < 5){
     if(N == 0){
       cout << "YES" << endl;
       return 0;
     }else{
       cout << "NO" << endl;
       return 0;
     }
   }else if(N == 5){
     if(S == "maerd" || S == "esare"){
       cout << "YES" << endl;
       return 0;
     }else{
      cout << "NO" << endl;
      return 0;
     }
   }else if(N == 6){
     if(S == "resare"){
       cout << "YES" << endl;
       return 0;
     }else{
       cout << "NO" << endl;
       return 0;
     }
   }else{
      string S1 = S.substr(0, 5);
      string S2 = S.substr(0, 6);
      string S3 = S.substr(0, 7);
    if(S1 == "maerd" || S1 == "esare"){
      S = S.erase(0, 5);
    }else if(S2 == "resare"){
      S = S.erase(0, 6);
    }else if(S3 == "remaerd"){
      S = S.erase(0, 7);
    }else{
      cout << "NO" << endl;
      return 0;
    }
  }
 }
}
