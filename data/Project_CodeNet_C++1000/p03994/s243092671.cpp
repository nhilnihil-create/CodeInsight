#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int n;
char s[100010];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	cin>>n;
	int a=0;
	while(n>0&&s[a+1]){
		if(n>='z'-s[a]+1&&s[a]!='a'){
			n-='z'-s[a]+1;
			s[a]='a';
		}
		a++;
	}
	while(n>='z'-'a'+1)n-='z'-'a'+1;
	s[a]=((s[a]-'a'+n)%('z'-'a'+1))+'a';
	cout<<s;
	return 0;
}