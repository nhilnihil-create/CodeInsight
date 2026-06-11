#include<iostream>
using namespace std;
#include<algorithm>
#include<map>
#define mod  998244353
#define int long long int
int32_t main()
{
     int k,t;
     cin>>k>>t;
     multimap<int,int> mp;
     int j,prev=0;
     for(j=1;j<=t;j++)
     {
		 int x;
		 cin>>x;
		 mp.insert({x,j});
	 }
	 int answer=0;
	 while(mp.size()!=0)
	 {
		 auto it=mp.end();
		 it--;
		 if(it->second==prev)
		 {
			 if(mp.size()==1)
			 {
				 answer+=(it->first);
				 break;
			 }
			 it--;
			 int val=it->first-1;
			 int type=it->second;
			 mp.erase(it);
			 prev=type;
			 if(val!=0)
			    mp.insert({val,type});
		 }
		 else
		 {
			 int val=it->first-1;
			 int type=it->second;
			 prev=type;
			 mp.erase(it);
			 if(val!=0)
			   mp.insert({val,type});
		 }
	 }
	 cout<<answer<<endl;
}
