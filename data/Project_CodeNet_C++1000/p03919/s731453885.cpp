/*  
    |\_/|
    |* *|
    \_+_/
*/
#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){

  cin.tie(0);     // cout と cin の同期を切る
  ios::sync_with_stdio(false);  /* cの stdioストリーム (printfとか)と*/

  int H,W;

  cin>>H>>W;

  string str;

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>str;

      if(str=="snuke"){
	printf("%c%d\n",'A'+j,i+1);
	return 0;
      }
    }
  }

  return 0;
  
}


