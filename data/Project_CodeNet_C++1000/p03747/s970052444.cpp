#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define x first
#define y second

namespace gwlthll
{
	typedef long long ll;
	typedef std::pair<int,int> pii;
	const int N=101000,INF=1000000007;
	ll sa[N],sb[N];
	pii s[N];
	int n,L,T,na,nb;

	bool cmp(pii A,pii B){return A.x==B.x?A.y<B.y:A.x<B.x;}

	void initialize()
	{
		scanf("%d%d%d",&n,&L,&T),na=nb=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&s[i].x,&s[i].y);s[i].y=3-s[i].y*2;
			if(s[i].y==1)sa[++na]=s[i].x;
			else sb[++nb]=s[i].x;
		}
	}
	inline int adj(int x){return (x%L+L)%L;}
	pii GetTheFirstPosition()
	{
		if(!na || !nb)return pii(adj(s[1].x+s[1].y*T),s[1].y);
		int ia,ib,k=s[1].y,rt=T*2;
		if(k>0)
		{
			ia=1,ib=1,k*=-1;
			rt-=sb[1]-sa[1];
		}
		else
		{
			ia=na,ib=1,k*=-1;
			rt-=adj(sb[1]-sa[na]);
		}
		if(rt<0)return pii(adj(s[1].x+s[1].y*T),s[1].y);
		while(1)
		{
			ll nt=L,tmp=na%nb;
			int tb=(ib-1+tmp)%nb+1,fk;
			nt+=(ll)L*(na/nb);
			fk=sb[tb]-sb[ib];if(fk<0)fk+=L;
			nt+=fk;
			
			if(rt>=nt)rt-=nt,ib=tb;
			else break;
		}

		while(1)
		{
//			printf("%d %d %d %d\n",ia,ib,k,rt);
			if(k>0)
			{
				int tb=ib%nb+1,nt=(sb[tb]-sb[ib]);
				if(nt<=0)nt+=L;
				if(rt<nt)break;
				rt-=nt,ib=tb;
			}
			else 
			{
				int ta=((ia-2+na*2)%na)+1,nt=(sa[ia]-sa[ta]);
				if(nt<=0)nt+=L;
				if(rt<nt)break;
				rt-=nt,ia=ta;
			}
//			printf("?\n");
			k*=-1;
		}

//		printf("%d %d %d %d\n",ia,ib,k,rt);
		
		int pos;
		
		if(k>0)pos=sa[ia];
		else pos=sb[ib];
		pos=adj(pos+k*T);

		return pii(pos,k);
	}
	void solve()
	{
		initialize();
		pii A=GetTheFirstPosition();

		for(int i=1;i<=n;i++)
			s[i].x=((s[i].x+T*s[i].y)%L+L)%L;
		std::sort(s+1,s+n+1,cmp);

		int pos=0;
		for(int i=1;i<=n;i++)
			if(s[i]==A){pos=i;break;}

		for(int cnt=n;cnt--;)
		{
			printf("%d\n",s[pos].x);
			pos=pos%n+1;
		}
	}
}

int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	gwlthll::solve();
	return 0;
}
