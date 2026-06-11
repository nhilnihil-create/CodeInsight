#include<cstdint>
#include<climits>
#include<cstdbool>
#include<cmath>
#include<iostream>
#include<vector>
#include<array>
#include<string>
#include<sstream>
#include<algorithm>

int main(){
	uint32_t a,b,c,tempa,tempb,tempc,i;
	std::cin>>a>>b>>c;
	if(a%2 || b%2 || c%2){
		std::cout<<0;
		return 0;
	}
	for (i = 1; i <= 1000000; ++i){
		tempa = (b+c)/2;
		tempb = (a+c)/2;
		tempc = (b+c)/2;
		if(tempa%2 || tempb%2 || tempc%2)
			break;
		a = tempa;
		b = tempb;
		c = tempc;
	}
	if(i != 1000001)
		std::cout<<i;
	else
		std::cout<<-1;
	return 0;
}
