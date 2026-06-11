#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int n,x=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x+=i;
	}
	cout<<x<<endl;
	return 0;
}