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
	ll w,a,b;
	cin>>w>>a>>b;
	if(a<b){
		cout<<max((b-(a+w)),0LL)<<"\n";
	}
	else{
		cout<<max(a-(b+w),0LL)<<"\n";
	}
    return 0; 
} 