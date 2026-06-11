#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int n, a, b, j = 0, k = 1;
  string s;
  cin >> n >> a >> b;
  cin >> s;
  REP(i,0,n){
    if(s[i] == 'c'){
     cout << "No" << endl;
    }else if(s[i] == 'a'){
      if(j >= a+b){
        cout << "No" << endl;
      }else{
        cout << "Yes" << endl;
        j++;
      }
    }else if(s[i] == 'b'){
      if(j >= a+b || k > b){
        cout << "No" << endl;
      }else{
        k++;
        j++;
        cout << "Yes" << endl;
      }
    }
  }

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}