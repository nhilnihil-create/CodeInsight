#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<cmath>
#define int long long int
int32_t main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int h,w;
	 cin>>h>>w;
	 int answer=1000000000000000;
	 int i,j;
	 int p1=(min(1LL,h%3))*w;
	 answer=min(answer,p1);
	 int p2=h*(min(1LL,w%3));
	 answer=min(answer,p2);
	 for(j=1;j<w;j++)
	 {
		 int val1=h*j;
		 int val2=(h/2)*(w-j);
		 int val3=(h-h/2)*(w-j);
		 int maxval=max(val1,max(val2,val3));
		 int minval=min(val1,min(val2,val3));
		 int here=maxval-minval;
		 answer=min(answer,here);
	 }
	 for(i=1;i<h;i++)
	 {
		 int val1=i*w;
		 int val2=(h-i)*(w/2);
		 int val3=(h-i)*(w-w/2);
		 int maxval=max(val1,max(val2,val3));
		 int minval=min(val1,min(val2,val3));
		 int here=maxval-minval;
		 answer=min(answer,here);
	 }
	 cout<<answer<<endl;
}
