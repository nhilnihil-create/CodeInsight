/*
 * WelcomeToAtCoder.cpp
 *
 *  Created on: 2020/02/19
 *      Author: black
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <list>
#include <cstring>
#include <stdio.h>
using namespace std;

int numlen = 0;

long long strSum(string str){
	long long sum = 0;
	string tmp;

	for(int i=0; i<str.length(); ++i){
		if (str[i] != '+'){
			tmp += str[i];
		}
		else{
			sum += stoll(tmp);
			tmp="";
		}
	}
	sum += stoll(tmp);
	return sum;
}

long long solve(string str, int i){
	long long sum = 0;
	if (str[str.length()-1] == '+'){
		return 0;
	}
	if (str.length() <= i){
		return strSum(str);
	}

	sum += solve(str, i+1);
	str.insert(i+1, "+");
	sum += solve(str, i+2);

	return sum;
}


int main(){
	string S;
	cin >> S;

	numlen = S.length() -1;

	long long total = 0;
	total = solve(S, 0);
	cout << total << endl;

	return 0;
}
