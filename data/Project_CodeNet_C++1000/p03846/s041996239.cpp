#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//cout<<"GfG!";
	long long int n, a[1000000], i, j, k, f = 1 ;
	unsigned long long int tot = 1, M = 1000000007;
	cin>>n;
	for (i = 0; i < n; i++)
	{
	    cin>>a[i]; 
	}
	sort(a, a + n);
	i = 0;  j = 0; 
	while (i < n)
	{
	    if (n == 1)
	    {   break;  }
	    else if (a[i] == 0 && a[i+1] != 0)
	    {
	        i++;   
	    }
	    else if (a[i] == 0 && a[i+1] == 0)
	    {       f = 0;  break;  }
	    else
	    {
	        if (i == n - 1)
	        {       f = 0;  break;  }
	        else if(a[i+1] == a[i] && (a[j+2] - a[j] == 2))
	        {
	            tot = (tot * 2) % M;
	            i += 2;   j += 2;   
	            if (j == n - 2)
	                j = 0;
	                
	        }
	        else
	        {
	            f = 0;  break;
	        }
	    }
	     
	}
	if (f)
	    cout<<tot;
	else
	    cout<<"0";
	return 0;
}