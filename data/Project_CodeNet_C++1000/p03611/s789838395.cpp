#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{ 
    int n;  
   cin >> n;    
   while (n--) 
  {        
      int x;       
      cin >> x;        
      a[x]++;
      a[x-1]++;       
      a[x+1]++;    
  }   
  int max=0;
  for(int i=0;i<100005;i++)
  {
	if(max<a[i])
	{
		max=a[i];
	}
  }
     cout <<max<< endl;  
  return 0;
}