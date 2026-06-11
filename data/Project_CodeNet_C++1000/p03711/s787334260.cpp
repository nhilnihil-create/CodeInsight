#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int x,y,xg=0,yg=0;
	cin >> x >> y;
	if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)xg=1;
	if(x==4||x==6||x==9||x==11)xg=2;
	if(x==2)xg=3;
	if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)yg=1;
	if(y==4||y==6||y==9||y==11)yg=2;
	if(y==2)yg=3;
	if(xg==yg){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}