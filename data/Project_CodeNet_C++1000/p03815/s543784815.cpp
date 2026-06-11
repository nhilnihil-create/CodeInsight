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
	long long n,i=0;
	cin>>n;
	if(n%11==6){
		i=1;
	}
	cout<<(long long)ceil(((n/11.0)*2))-i<<endl;
    return 0; 
} 