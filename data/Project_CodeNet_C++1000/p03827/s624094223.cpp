#include<bits/stdc++.h>
using namespace std;
int  main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x=0;
	vector<int> v;
	for (int i = 0; i < n ; ++i)
	{
		/* code */
		if(s[i] == 'I'){
			x++;
			v.push_back(x);
		}
		else if(s[i] == 'D'){
			x--;
			v.push_back(x);
		}
	}
	if(*max_element(v.begin(), v.end()) > 0){
		cout<<*max_element(v.begin(), v.end())<<endl;
	}
	else{
	cout<<0<<endl;	
	}
	return 0;
}