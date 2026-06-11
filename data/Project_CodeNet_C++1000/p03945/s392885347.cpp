#include<bits/stdc++.h>
#define  fuckit(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
int main()
{
	fuckit();
	string s;
	cin>>s;
	int i,n=s.size(),cnt=0;

		for(i=0;i<n;i++){
			if(s[i]!=s[i+1]){
				cnt++;
			}
		}
	cout<<cnt-1<<endl;
	return 0;	
}
