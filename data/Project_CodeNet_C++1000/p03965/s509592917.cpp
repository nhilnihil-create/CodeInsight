#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

	int ans = 0;
	string s;
	cin>>s;
	string temp = "";
	for(int i=0;i<s.length();i++){
			temp += (i % 2 == 0) ? 'g' : 'p';
	}
	ans = s.length() /  2;
	for(int i=0;i<s.length();i++){
			if(s[i] == 'p' && temp[i] == 'g'){
					ans--;
			}
			else if(s[i] == 'p' && temp[i] == 'p')
				ans--;
	}
	
	cout<<ans<<endl;
}

