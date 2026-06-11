#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;

	long long hlfa=abs((a/2)*b*c-(a-a/2)*b*c);
	long long hlfb=abs((b/2)*a*c-(b-b/2)*a*c);
	long long hlfc=abs((c/2)*a*b-(c-c/2)*a*b);
	long long mn=min(hlfa,hlfb);	
	mn=min(mn,hlfc);	
	cout<<mn<<"\n";
	return 0;
}
