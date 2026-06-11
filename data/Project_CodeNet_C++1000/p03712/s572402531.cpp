#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int main()
{
	
int n,m;
string s;
cin>>n>>m;

for(int i=-1;i<=m;i++)cout<<"#";cout<<endl;
while(n--){cin>>s;cout<<"#"<<s<<"#"<<endl;}
for(int i=-1;i<=m;i++)cout<<"#";cout<<endl;


}

