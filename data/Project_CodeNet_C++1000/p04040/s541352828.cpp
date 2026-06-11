#include<iostream>
using namespace std;
#define int long long int
#define mod 1000000007
int fac[2000001];
void function()
{
	fac[0]=1;
	int j;
	for(j=1;j<=2000000;j++)
	{
		fac[j]=(j*fac[j-1])%mod;
	}
}
int power(int x, int y, int p) 
{ 
    int res = 1;
  
    x = x % p;  
  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
int nCrModPFermat(int n, int r, int p) 
{ 
	if(r>n||r<0)
	  return 0;
   if (r==0) 
      return 1; 
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
int32_t main()
{
	function();
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	if(h==1)
	{
		if(a<h)
		cout<<1<<endl;
		else
		cout<<0<<endl;
		exit(0);
	}
	if(w==1)
	{
		if(b<w)
		cout<<1<<endl;
		else
		cout<<0<<endl;
		exit(0);
	}
	int val[h+1]={0};
	int i;
	int col=b+1;
	for(i=1;i<=h;i++)
	{
		if(i>h-a)
		{
			val[i]=val[i-1];
			continue;
		}
		int total=i+col-2;
		val[i]=nCrModPFermat(total,b,mod);
	}
	int answer=0;
	for(i=1;i<=h-1;i++)
	{
		col=b+2;
		int total=h+w-(i+col);
		int r=(w-col);
		int temp=nCrModPFermat(total,r,mod);
		int temp2=val[i];
		int curr=(temp*temp2)%mod;
		answer+=curr;
		answer%=mod;
	}
	answer+=val[h];
	answer=answer%mod;
	cout<<answer<<endl;
}
