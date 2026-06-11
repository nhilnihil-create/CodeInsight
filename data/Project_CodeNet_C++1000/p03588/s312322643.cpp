#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long a,b,max = 0,point;
  cin >> n;
  for(int i = 0;i <n;i++){
    cin >> a >> b;
    if(max < a)max = a,point = b;
  }
  cout << max + point << endl;
}