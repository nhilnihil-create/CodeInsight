#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif
int d[256];
int main()
{
	
string s;
cin>>s;
for(auto i:s)d[i]=1;
for(int i='a';i<='z';i++)if(d[i]==0){cout<<(char)i<<endl;return 0;}
puts("None");


}

