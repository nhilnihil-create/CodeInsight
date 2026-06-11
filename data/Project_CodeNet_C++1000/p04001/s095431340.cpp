#include<iostream>
#include<string>
using namespace std;
long long pow(int x,int y){
  long long z = 1;
  while(y){
    z *= x;y--;
  }
  return z;
}//昔の話　もっと高速なやつある
int main(){
  string s;cin >> s;
  if(s.size()==1){
    cout << int(s[0]-'0') << endl;
    return 0;
  }
  int n = s.size(),num[n],i,j,c,b[n] = {};b[0] = -1,b[n-1] = 1;long long ans = 0;
  //b[n]が手書き
  for(i=0;i<n;i++) num[i] = s[i]-'0';
  for(i=0;i<pow(2,n-1);i++){
    b[0]++;//最初のやつに1足して
    for(j=0;j<n-1;j++){
      if(b[j]==2){
  		b[j+1]++;b[j]=0;//2になったら次の数値に繰り上げる
      }
    }
    for(j=0;j<n;j++){
      c = j;
      while(b[c]==0) c++;
      ans += num[j]*pow(10,c-j);
    }
  }
  cout << ans << endl;
  return 0;
}
