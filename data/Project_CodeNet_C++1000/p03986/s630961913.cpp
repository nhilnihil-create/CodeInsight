#include<iostream>
#include<cstring>
#include<deque>
using namespace std;
const int maxn=2e5+10;
char ch[maxn];
int len;
deque<char> Q;
int main(){
	cin>>ch;
	len=strlen(ch);
	Q.clear();
	Q.push_back('A');
	for(int i=0;i<len;i++){
		if(ch[i]=='S')
			Q.push_back(ch[i]);
		else if(ch[i]=='T'){
			char u=Q.back();
			if(u=='T'||u=='A')
				Q.push_back(ch[i]);
			else if(u=='S')
				Q.pop_back();
		}	
	}
	int ans=Q.size();
	if(ans%2==1) ans--;
	cout<<ans<<endl;
	return 0;
}