  /*  HARD WORK FOREVER PAYS  */
#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
typedef pair<int,int> PII; 
int main() 
{ 
	turbo();
	string s,s1;
	cin>>s>>s1;
	for(int i=0;i<s.size()&&i<s1.size();i++){
		cout<<s[i]<<s1[i];
	}
	if(s.size()!=s1.size()){
		cout<<s[s.size()-1]<<"\n";
	}
	return 0; 
} 