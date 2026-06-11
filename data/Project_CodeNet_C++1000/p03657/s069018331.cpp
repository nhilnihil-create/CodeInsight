#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <unordered_map>
#include <numeric>
#include <sstream>
#include <functional>
using namespace std;

int main()
{
	int a=0,b=0;
	cin >> a >> b;

	if((a+b)%3 == 0 || a%3 == 0 || b%3 == 0){
		puts("Possible");
	}else{
		puts("Impossible");
	}

	return 0;
}
