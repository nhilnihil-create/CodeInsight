#include<bits/stdc++.h>
#define  fuckit(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
int main()
{
	fuckit();
	string s,t="";
	cin>>s;
	int n=s.size(),i,cnt=0;
	for(i=0;i<n;i++){
		t+=s[i];
		if(t=="dream"){
			if(i<n-2&&(s[i+1]!='e'||s[i+2]!='r')){
				cnt+=t.size();
				t="";
			}
			else if(i<n-3&&(s[i+1]=='e'&&s[i+2]=='r'&&s[i+3]=='a')){
				cnt+=t.size();
				t="";
			}
			else if(i==n-1){
				cnt+=t.size();
			}

		}
		else if(t=="dreamer"){
			cnt+=t.size();
			t="";
		}
		else if(t=="erase"){
			if(i<n-1&&s[i+1]=='r'){
				cnt+=t.size()+1;
				t="";
				i++;
			}
			else{
				cnt+=t.size();

				t="";
			}
		}

	}
	if(cnt==n){
		cout<<"YES"<<"\n";
	}
	else{
		cout<<"NO"<<"\n";
	}
	return 0;	
}
