#include<iostream>
#include<string>
using namespace std;
	
int main(){
  	string S;
  	string ans;
	cin >> S;
  	for(int i = 0 ; i < 12; i++){
    	if(i!= 4){
          	ans +=S[i];
        }else{
          	ans +=" ";
        	ans +=S[i];
        }
    }
  	cout << ans << endl;

}