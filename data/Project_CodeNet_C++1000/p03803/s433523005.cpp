#include <stdio.h>
#include <iostream>
using namespace std;

int A,B;
int main (){
	cin >>A>>B;
	if (A==B){
		cout<<"Draw";
	}else if (A==1){
		cout<<"Alice";
	}else if (B==1){
		cout<<"Bob";
	}else if (A<B){
		cout<<"Bob";
	}else if (A>B){
		cout<<"Alice";
	}
}