#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  char s[n];
  int overseas=0;
  rep(i,n){
    cin >> s[i];
    if(s[i]=='b'){

    }
  }
  int max = a+b;
  int passed=0;
  rep(i,n){
    switch(s[i]){
      case 'a':
        if(max>passed){
          cout << "Yes" <<endl;
          passed++;
        }
        else cout <<"No" <<endl;
        break;
      case 'b':
        if(max>passed && b>overseas){
          cout << "Yes" <<endl;
          passed++;
          overseas++;
        }
        else cout <<"No" <<endl;
        break;
      case 'c':
        cout << "No" <<endl;
        break;
    }
  }
  return 0;
}