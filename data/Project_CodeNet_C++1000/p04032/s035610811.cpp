#include <bits/stdc++.h>
using namespace std;
void fast(){
cin.tie(0);
cin.sync_with_stdio(0);
}
 
int main()
{
	fast();
	string s;
	cin>>s;
	if(s.size()==2&&s[1]==s[0]){cout<<"1 2";return 0;}
	for(int i=0;i<s.size()-2;i++){
			int freq[130]={};
		for(int j=i;j<i+3;j++){
			freq[s[j]]++;
			if(j==i+2){for(int k=97;k<=122;k++){
				if(freq[k]>=2){cout<<i+1<<" "<<j+1;return 0;}
 
			}
			}
		}
	}
	cout<<"-1 -1";
    return 0;
}