#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string w;
  cin >> w;
  int n = w.size();
  map<char,int> a;
  for(int i=0; i<n; ++i){
    a[w[i]]++;
  }
  for(int i=0; i<n; ++i){
    if(a[w[i]]>0){
      if(a[w[i]]%2!=0){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}