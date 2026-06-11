#include<iostream>
using namespace std;

int main() 
{
	long long A,B,C;
	long long ans;
	cin >> A >> B >> C;
	long long mmin = min(A,min(B,C));
	long long mmin2;
	if(A%2 == 0 || B%2 == 0 || C%2 == 0) 
	{
		cout << 0 <<endl;
	} 
	else 
	{
		if(mmin==A) 
		{
			mmin2 = min(B,C);
		} 
		else if(mmin == B) 
		{
			mmin2 = min(A,C);
		} 
		else if(mmin == C)
		{
			mmin2 = min(A,B);
		}
		cout << mmin*mmin2;
	}
}