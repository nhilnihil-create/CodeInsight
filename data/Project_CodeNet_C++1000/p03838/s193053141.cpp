#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y;
	int ans;

 	cin >> x >> y;

	if (x>0) {
		if (y>0) {
        	if(x>y) ans=x-y+2;
             else ans=y-x;
	    }else if(y<0){
        	if(x>-y) ans=x+y+1;
             else ans=-y-x+1;
	    }else{
         	ans=x+1;
	    }
    }else if(x<0){
		if (y>0) {
        	if(-x>y) ans=-x-y+1;
             else ans=x+y+1;
	    }else if(y<0){
        	if(-x>-y) ans=-x+y;
             else ans=x-y+2;
	    }else{
         	ans=-x;
		}
    }else{
		if (y>0) {
         	ans=y;
	    }else if(y<0){
         	ans=-y+1;          
	    }else{
         	ans=y;
        }
    }
  
   
	cout << ans << endl;
	return 0;
}
