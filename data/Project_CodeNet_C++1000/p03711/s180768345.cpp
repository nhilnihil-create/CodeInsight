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
	 int arr1[7]={1,3,5,7,8,10,12};
	 int arr2[4]={4,6,9,11};
	 int arr3[1]={2};
	 int x,y;
	 cin>>x>>y;
	 bool result=false;
	 int count=0;
	 int i;
	 for(i=0;i<7;i++)
	 {
		 if(arr1[i]==x||arr1[i]==y)
		   count++;
	 }
	 if(count==2)
	 {
		 result=true;
	 }
	 count=0;
	 for(i=0;i<4;i++)
	 {
		 if(arr2[i]==x||arr2[i]==y)
		   count++;
	 }
	 if(count==2)
	 {
		 result=true;
	 }
	 if(result)
	 {
		 cout<<"Yes"<<endl;
	 }
	 else  
	   cout<<"No"<<endl;
}
