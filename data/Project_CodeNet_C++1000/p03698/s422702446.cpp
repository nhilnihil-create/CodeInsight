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
cout<< (set<char>(s.begin(),s.end()).size()==s.size()?"yes":"no")<<endl;;
}

