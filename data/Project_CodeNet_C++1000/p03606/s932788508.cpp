#include<cstdint>
#include<limits>
#include<cstdbool>
#include<cmath>
#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<sstream>
#include<algorithm>

int main(){
	int n;
	int sum=0;
	std::cin>>n;
	int a,b;
	for(int i =0; i < n ;++i){
		std::cin>>a>>b;
		sum+=b-a+1;
	}
	std::cout<<sum;


}
