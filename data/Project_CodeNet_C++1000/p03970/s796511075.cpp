#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
string st,st1;
int djy,ll,gs;
int main()
{
cin>>st;
ll=st.size();
st1="CODEFESTIVAL2016";
while(djy<ll)
{
	if(st[djy]!=st1[djy])gs++;
	djy++;
}
cout<<gs<<endl;
return 0;
}
