#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,p=0,q=0;
  cin >> n >> a >> b;
  char s[n+1];
  for(int i=0;i<n;i++){
    cin >> s[i];
    if(s[i]=='a'){
      if(p<a+b){
        cout << "Yes" << endl;
        p++;
      }
      else cout << "No" << endl;
    }
    else if(s[i]=='b'){
      q++;
      if(p<a+b){
        if(q<=b){
          cout << "Yes" << endl;
          p++;
        }
        else cout << "No" << endl;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }
}
