#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// scanf
#pragma warning(disable: 4996)


/*
	v:vector  type:型  order:greater or less
*/
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
/*
	v:vector  default_value:初期値
*/
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
/*
	丸め
*/
#define _round(v) round(v)
/*
	2乗 / 3乗  default_value:初期値
*/
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)


int main()
{
	int n, k, x, y;
	cin >> n >> k >> x >> y;

	int result = n * x - ((n > k) ? (n-k)*(x-y):0);

	printf("%d\n", result);
	return 0;
	//	std::cout << "Hello World!\n"; 
}
