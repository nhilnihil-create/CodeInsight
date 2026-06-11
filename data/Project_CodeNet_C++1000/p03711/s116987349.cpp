#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;



int main(){
	vector<int> a={1,3,5,7,8,10,12};
	vector<int> b={4,6,9,11};
	
	int x,y;
	cin >> x >> y;
	
	if(x==2 || y==2){
		cout << "No" << endl;
		return 0;
	}
	
	int check=0;
	for(int i=0;i<a.size();i++){
		if(x==a[i])check++;
		if(y==a[i])check++;
	}
	if(check==2){
		cout << "Yes" << endl;
		return 0;
	}
	
	check=0;
	for(int i=0;i<b.size();i++){
		if(x==b[i])check++;
		if(y==b[i])check++;
	}
	if(check==2){
		cout << "Yes" << endl;
		return 0;
	}
	
	cout << "No" << endl;
	return 0;
}
