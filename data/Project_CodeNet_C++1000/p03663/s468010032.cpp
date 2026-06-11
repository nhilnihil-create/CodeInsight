#include<cstdio>


using ll=long long;


int ask(ll n)
{
	char r[1+2];

	printf("? %lld\n", n);
	fflush(stdout);
	scanf("%1s", r);

	return r[0]=='Y';
}


int search_one(ll offset, int s_initial)
{
	int s, e, c, r, ans=0;

	s=s_initial;
	e=9;
	for(;s<=e;)
	{
		c=(s+e)/2;
		r=ask(c+offset);

		if(r)
		{
			s=c+1;
			ans=c;
		}
		else
		{
			e=c-1;
		}
	}
	return ans;
}


int search_last(ll offset)
{
	int s, e, c, r, ans=0;
	ll v;

	s=0;
	e=9;
	for(;s<=e;)
	{
		c=(s+e)/2;
		v=c+offset;
		r=ask(v*10);

		if(!r)
		{
			s=c+1;
		}
		else
		{
			e=c-1;
			ans=c;
		}
	}
	return ans;
}



int main(void)
{
	ll n, offset;
	int d;

	if(!ask(1000000000))
	{
		for(d=1,n=10;d<10;d++,n*=10)
		{
			if(!ask(n)) break;
		}
	}
	else
	{
		n=999999999;
		for(;n;n/=10)
		{
			if(!ask(n))
			{
				printf("! %lld\n", n+1);
				return 0;
			}
		}
		printf("! 1\n");
		return 0;
	}

	offset=0;
	for(int i=0;i+1<d;i++)
	{
		offset+=search_one(offset, i==0);
		offset*=10;
	}

	ll ans=offset+search_last(offset);

	printf("! %lld\n", ans);
	fflush(stdout);

	return 0;
}
