#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

string smh(int & x, int & y)
{
	int group1[]={1,3,5,7,8,10,12}, group2[] = {4,6,9,11};
	int len1 = sizeof group1/ sizeof group1[0];
	int len2 = sizeof group2/ sizeof group2[0];
	char cx = 'x', cy = 'y';
	for(int i = 0; i < len1; i++){
		if( x == group1[i] )
			cx = '1';
		if( y == group1[i] )
			cy = '1';
	}
	for(int i = 0; i < len2; i++){
		if( x == group2[i] )
			cx = '2';
		if( y == group2[i] )
			cy = '2';
	}
	if( cx == cy )
		return "Yes";
	return "No";
}

int main()
{
	int x, y;
	cin >> x >> y;
	if( x == y )
		cout << "Yes";
	else
		cout << smh(x,y);
	return 0;
}