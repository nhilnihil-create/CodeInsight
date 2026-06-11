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
typedef pair<int,pair<int,int>> PII;
int main() 
{ 
	turbo();
	int i=0;
	string s;
	cin>>s;
	int j=s.length()-1;
	for(i=0;i<=j;i++){
		if(s[i]=='A'){
			break;
		}
	}
	for(;j>=0;j--){
		if(s[j]=='Z'){
			break;
		}
	}
	cout<<j-i+1<<endl;
    return 0; 
} 