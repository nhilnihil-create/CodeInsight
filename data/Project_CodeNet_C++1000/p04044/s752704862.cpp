#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int L,n;

int main(){
cin>>n>>L;

vector<string> s{};

	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		s.emplace_back(str);

	}

	sort(s.begin(),s.end());

string ans;
  for (int i = 0; i < n; i++) {
	ans +=s[i];
	}
cout<<ans<<endl;

return 0;
}

