/*
	Problem Statement
	
	Iroha loves Haiku. Haiku is a short form of Japanese poetry. A Haiku consists of three phrases with 5, 7 and 5 syllables, in this order.To create a Haiku, Iroha has come up with three different phrases. 
	These phrases have A, B and C syllables, respectively. Determine whether she can construct a Haiku by using each of the phrases once, in some order.
*/

#include<bits/stdc++.h>
using namespace std;

bool helper(int a, int b, int c)
{
	int fc=0,sc=0;
	if(a==5)
		fc++;
	else if(a==7)
		sc++;
	
	if(b==5)
		fc++;
	else if(b==7)
		sc++;
	
	if(c==5)
		fc++;
	else if(c==7)
		sc++;
	return fc==2 && sc==1;
}


int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(helper(a,b,c))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
