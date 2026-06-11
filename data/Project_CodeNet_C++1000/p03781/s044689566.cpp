#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;
int main () { 
	long long x,y;
	cin >> x;
	y= 0;
	for(int i = 1;i <= x; ++i){
		y = y+i;
		if(y >= x){
			cout << i << endl;
				break;
		}
	}	
} 			

