#include <iostream>
#include <algorithm>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	vector <int> ve;
	ve.push_back(a);
	ve.push_back(b);
	ve.push_back(c);
	sort(ve.begin(),ve.end());
	
  	if(ve[0]+ve[1]==ve[2])
	{
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}