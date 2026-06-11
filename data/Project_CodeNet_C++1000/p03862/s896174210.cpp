#include <iostream>
#include <string>
#define loop(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

int main()
{
long int n;
long long int x;
long long int ans=0;
cin>>n>>x;


long long int e[n];

loop(i,n) cin>>e[i];

for(int i=0;i<n-1;i++)
	{
	    if(e[i]>x){
            ans+=e[i]-x;
            e[i]=x;
	    }

		if(e[i]+e[i+1]>x){

            ans+=e[i]+e[i+1]-x;
            e[i+1]=x-e[i];
		}


	}

cout<<ans<<endl;
}
