#include<bits/stdc++.h>
#include<iostream>
#include <cstdio>
#define endl '\n'
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c;
	cin>>a>>b>>c;
	int turn;
	if(a==b && b==c && c==a) {
            if(a%2==1)turn = 0;
            else if(a%2==0)turn = -1;
    }
	else{
            turn = 0;
	while(!(a%2) && !(b%2) && !(c%2))
	{
		int A = (b/2)+(c/2);
		int B = (a/2)+(c/2);
		int C = (a/2)+(b/2);
		turn++;
		a = A,b = B,c = C;
		//cout<<a<<" "<<b<<" "<<c<<endl;
	}
	}
	cout<<turn<<endl;
	return 0;
}
