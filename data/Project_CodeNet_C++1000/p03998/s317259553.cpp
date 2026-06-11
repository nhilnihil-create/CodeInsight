#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star; //処理早くするためのおまじない
int main(){

string Sa,Sb,Sc;
cin>>Sa>>Sb>>Sc;

string next;
next.push_back(Sa[0]);

	while(true)
	{
		if(next == "a")
		{
			if(Sa.empty())
			{
				cout<<"A"<<endl;
				break;
			}
			next=*Sa.begin();
			Sa.erase(Sa.begin());
	 	}
	 	if(next == "b")
	 	{
			if(Sb.empty())
			{
				cout<<"B"<<endl;
				break;
			}
		next=*Sb.begin();
		Sb.erase(Sb.begin());
	 	}
	 	if(next == "c")
	 	{
			if(Sc.empty())
			{
				cout<<"C"<<endl;
				break;
			}
		next=*Sc.begin();
		Sc.erase(Sc.begin());
	 	}
	}
	return 0;
}


