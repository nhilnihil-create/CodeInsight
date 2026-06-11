#include <iostream>
#include <cmath>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long a,b;
	cin>>a>>b;
	if(abs(a-b)<=1)
	{
		
		cout<<"Brown";
	}
	else cout<<"Alice";
	return 0;
}