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
	int a,b,c,d,ANS=0;
	vector<int>V(101,0);
	cin>>a>>b>>c>>d;
	for(int i=a;i<b;i++){
		V[i]=1;
	}
	for(int i=c;i<d;i++){
		if(V[i]==1){
			ANS++;
		}
	}
	cout << ANS << endl;
}