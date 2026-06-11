#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int p = 0, q = 0;
  for(int i = 0; i < n; i++){
    if(a[i] % 2 == 0) p++;
    else q++;
  }
  if(q % 2 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}