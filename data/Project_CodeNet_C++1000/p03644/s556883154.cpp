#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int n;
  cin>>n;

  int max_wk=0,output=1;
  for(int i=2;i<=n;i+=2){
    int wk=i;
    int cnt=0;
    do{
      if(wk%2==0){
        wk/=2;
        cnt++;
      }
    }while(wk%2==0);
    if(max_wk<cnt){
      output=i;
      max_wk=cnt;
    }
  }

  cout<<output<<endl;

  
	return 0;
}