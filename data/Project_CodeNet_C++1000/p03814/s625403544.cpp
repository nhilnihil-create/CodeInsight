#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif


int main()
{
	
	string s;
	cin>>s;
	cout<<(max(0,1+(int)s.find_last_of('Z')-(int)s.find_first_of('A')))<<endl;
	
}

