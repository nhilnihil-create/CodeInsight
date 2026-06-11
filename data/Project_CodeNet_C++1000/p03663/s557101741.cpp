#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[20],n,s,h;
string v;
main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	a[0]=1;
	for(int i=1;i<=15;i++)
	  a[i]=a[i-1]*10;
	s=0;
	for(int i=10;i>=1;i--)
	  {
		int check = a[i]-1;
		cout << "? " << check << "\n";
		fflush(stdout);
		cin >> v;
		//h++;
		if(v == "N") 
		{
			s = i+1;
		break;
	    }
	  }
	if(s==0)
	  {
	  	for(int i=10;i>=0;i--)
	  	 {
		 int check = a[i];
		 cout << "? " << check << "\n";
		 fflush(stdout);
		 cin >> v;
		 //h++;
		 if(v == "Y"&& i==10) 
		   {
		   	cout << "! " << 1 << "\n";
		    fflush(stdout);
			//s = i+1;
		    exit(0);
		   }
		  if(v=="Y")
		   {
		   	s=i+1;
		   	break;
		   }
	      }
	    
	  }
	int l,r,gi;
	l=a[s];
	r=a[s+1]-10;
	gi=0;
	while(l<r)
	 {
	 	int mid;
	 	mid=(l+r)/2;
	 	if(mid==gi) break;
		 else gi=mid;
	 	cout << "? " << mid << "\n";
		fflush(stdout);
		cin >> v;
		if(v == "Y") r=mid;
		  else l=mid;
	    h++;
	 }
	if(r/10!=0) cout<<"! "<<r/10<<endl;
	  else cout<<"! "<<1<<endl;
    fflush(stdout);
    //cout<<h<<endl;
}
