#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
int main(){
  int i,n,cnt[4]={0};
  string s;
  cin >> s;
  n = s.size();
  rep(i,n){
    switch(s[i]){
      case 'N':
        cnt[0]++;
        break;
      case 'W':
        cnt[1]++;
        break;
      case 'S':
        cnt[2]++;
        break;
      case 'E':
        cnt[3]++;
        break;
    }
  }
  int flag=1;
  for(i=0;i<4;i++){
    if(cnt[i]>=1 && cnt[(i+2)%4]==0){
      flag=0;
      break;
    }
  }
  cout << (flag==1 ? "Yes" : "No") << endl;
  return 0;
}