#include<bits/stdc++.h>

#define pb push_back
#define ll long  long
#define endl "\n"
#define ui unsigned integer

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	set<int>v;
	int a,b,c,d,i,t,count=0;
	bool x=0;
	cin>>t;
	while(t--){
        cin>>a;
       auto it=v.find(a);
       if(*it!=a){v.insert(a);}
       else{v.erase(a);}
	}
	cout<<v.size()<<endl;




	return 0;
}
