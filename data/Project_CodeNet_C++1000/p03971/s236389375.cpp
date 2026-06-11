#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int k = 0, e = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'b') e++;
    if(s[i] == 'a'){
      if(a+b > k){
        cout << "Yes" << endl;
        k++;
      }else{
        cout << "No" << endl;
      }
    }else if(s[i] == 'b'){
      if(a+b > k && b >= e){
        cout << "Yes" << endl;
        k++;
      }else{
        cout << "No" << endl;
      }
    }else cout << "No" << endl;
  }
}