#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
#define sqr(int) (int * int)
#define sqr3(int) (int * int * int)
#define pi M_PI
#define n "\n"


	
  void solve(){
	  int a,b,c;
	  cin >> a >> b >> c;
	  int x=0,y=0;
	  if(a == 5){x+=1;}
	  if(a == 7){y+=1;}
	  if(b == 5){x+=1;}
	  if(b == 7){y+=1;}
	  if(c == 5){x+=1;}
	  if(c == 7){y+=1;}
	  
	  if(x == 2 && y == 1){
		  cout << "YES";
	  }
	  else{
		  cout << "NO";
	  }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);
	solve();
}
	
	

		
		
		
		
	



