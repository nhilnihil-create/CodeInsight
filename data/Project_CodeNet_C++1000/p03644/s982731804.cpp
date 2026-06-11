#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,cou=0,res=1;
  	cin >> n;
  	for(int i=1;i<=n;i++){
    	int a =i,counter=0;
      	if(i%2==0){
        	while(a>=0){
            	a /= 2;
              	counter++;
              	if(a%2==1) break;
             }
        }
      	if(counter>cou){
        	cou=counter;
          	res=i;
        }
    }
	cout<<res<<endl;
}