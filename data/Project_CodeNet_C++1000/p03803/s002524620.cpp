#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
	int a,b;
  cin >> a >> b;
  if(a==b) cout << "Draw" << endl;
  else{
   if(a==1){
    	cout << "Alice"  << endl;
   }
    else if(b==1){
     cout << "Bob"  << endl;
    }
    else if(a<b){
     	cout << "Bob"  << endl;
    }
    else{
     cout <<"Alice"  << endl;
    }
  }
  
  
  return 0;
    

}
