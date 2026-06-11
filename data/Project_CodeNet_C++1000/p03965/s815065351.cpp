#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s; cin>>s;
	int len = s.size();
	int ans = 0;
	int g_num = 0, p_num = 0;
	for(int i = 0; i < len; i++){
		if(i%2 == 0){
			if(s[i] == 'p')ans--;
		}
		else{
			if(s[i] == 'g') ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

