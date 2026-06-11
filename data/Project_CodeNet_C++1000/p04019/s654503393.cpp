#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;
int main() {
	string s;
	cin >> s;
	int a=0,b=0,c=0,d=0;
	for(auto x:s){
	    // coNSNNSNSNut << x<<" ";
	     if(x=='S'){
	          a+=1;
	     }
	     if(x=='N'){
	          b+=1;
	     }
	     if(x=='W'){
	          c+=1;
	     }
	     if(x=='E'){
	          d+=1;
	     }
	}
// 	cout << endl;
	int done = 0;
	if((a>0&&b>0)||(a==0&&b==0)){
	          if((c>0&&d>0)||(c==0&&d==0)){
	               cout << "Yes";
	               done = 1;
	          }
	     }
	
	if(done==0){
	
	     cout << "No";
	}
	return 0;
}
