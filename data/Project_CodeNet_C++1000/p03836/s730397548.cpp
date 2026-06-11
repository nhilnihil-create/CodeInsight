#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;


int main()
{
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	int dx,dy;
	dx = tx - sx;
	dy = ty - sy;
	rep(i,dy) cout<<"U";
	rep(i,dx) cout<<"R";
	rep(i,dy) cout<<"D";
	rep(i,dx) cout<<"L";
	cout<<"LU";
	rep(i,dy) cout<<"U";
	rep(i,dx) cout<<"R";
	cout<<"RDRD";
	rep(i,dy) cout<<"D";
	rep(i,dx) cout<<"L";
	cout<<"LU"<<endl;
	return 0;
}
