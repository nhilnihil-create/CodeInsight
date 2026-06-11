#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string a,b;
  cin >> a >> b;
  
  int lena = a.size();
  int lenb = b.size();
  if(lena > lenb){
    cout << "GREATER" << endl;
    return 0;
  }else if(lena < lenb){
    cout << "LESS" << endl;
    return 0;
  }
  
  if(a > b){
    cout << "GREATER" << endl;
  }else if(a < b){
    cout << "LESS" << endl;
  }else{
    cout << "EQUAL" << endl;
  }
}