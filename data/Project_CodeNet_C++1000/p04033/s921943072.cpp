#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;
int main() {
	int a,b;
	cin >> a >> b;
	if(a==0||b==0||(a>0&&b<0)||(b>0&&a<0)){
	     
	          cout << "Zero";
	     
	}
	if(a==b){
	     if(a<0){
	          cout << "Negative";
	     }
	     if(a>0){
	          cout << "Positive";
	     }
	     if(a==0){
	          cout << "Zero";
	     }
	}
	else if(a>0&&b>0){
	     cout << "Positive";
	}
	else if(a<0&&b<0){
	   if((b-a+1)%2==0){
	        cout << "Positive";
	   }else{
	        cout << "Negative";
	   }
	}
	return 0;
}
