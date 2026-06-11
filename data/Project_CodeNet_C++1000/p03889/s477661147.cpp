#include<bits/stdc++.h>
using namespace std;
int main()
{char a[100005];int n,i;
scanf("%s",a);
n=strlen(a);
if(n%2==1)
  {cout<<"No"<<endl;
  return 0;
  }
for(i=0;i<n;i++)
  if((a[i]==a[n-i-1])||(a[i]=='q'&&a[n-i-1]=='d')||(a[i]=='q'&&a[n-i-1]=='b')||(a[i]=='p'&&a[n-i-1]=='d')||(a[i]=='p'&&a[n-i-1]=='b'))
    {cout<<"No"<<endl;
    return 0;
	}
cout<<"Yes"<<endl;
return 0;
}