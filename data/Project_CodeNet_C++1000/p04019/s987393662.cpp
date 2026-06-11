#include <bits/stdc++.h>
using namespace std;


int main(){
	string s;
	cin >> s;
	int a=s.size();
	int n=0;
	int m=0;
	int w=0;
	int e=0;
	for(int i=0;i<a;i++){
		if(s.at(i)=='N'){
			n++;
		}else if(s.at(i)=='S'){
			m++;
		}else if(s.at(i)=='E'){
			e++;
		}else if(s.at(i)=='W'){
			w++;
		}
	}
	if((n==0&&m!=0)||(n!=0&&m==0)||(e==0&&w!=0)||(e!=0&&w==0)){
		cout << "No" <<endl;
	}else{
		cout << "Yes" << endl;
	}
}