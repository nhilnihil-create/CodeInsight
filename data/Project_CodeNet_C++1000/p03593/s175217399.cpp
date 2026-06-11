#include <cstdio>
#include <cstring>

inline bool isdig(const char &c)
{
	return c>='0'&&c<='9';
}

inline bool islow(const char &c)
{
	return c>='a'&&c<='z';
}

inline char gc(void)
{
	#ifndef local_lwq
	static char buf[100000],*p1=buf,*p2=buf;

	if(p1!=p2) return *p1++;

	p1=buf;
	p2=p1+fread(buf,1,100000,stdin);

	return p1==p2?EOF:*p1++;
	#else
	return getchar();
	#endif
}

template<typename T> inline T read(void)
{
	T ret=(T)0;
	bool neg=false;
	char c=gc();

	while(!isdig(c))
	{
		neg|=(c=='-');
		c=gc();
	}
	while(isdig(c))
	{
		ret=ret*10+c-'0';
		c=gc();
	}
	ret=neg?-ret:ret;

	return ret;
}

int n,m,tcnt[30],mcnt[5];

bool judge(void)
{
	if(!mcnt[1]&&!mcnt[2]&&!mcnt[3]) return true;
	if(mcnt[1])
	{
		if(mcnt[3]) return false;
		if(mcnt[1]!=1) return false;
		if(!(n&1)||!(m&1)) return false;
		if(mcnt[2]>(n>>1)+(m>>1)) return false;
		return true;
	}
	if(mcnt[3])
	{
		if(mcnt[1]) return false;
		if(mcnt[3]!=1) return false;
		if(!(n&1)||!(m&1)) return false;
		if(mcnt[2]+1>(n>>1)+(m>>1)) return false;
		return true;
	}
	if(n&1)
	{
		if(mcnt[2]>(m>>1)) return false;
		return true;
	}
	if(m&1)
	{
		if(mcnt[2]>(n>>1)) return false;
		return true;
	}
	
	return false;
}

int main()
{
	memset(tcnt,0,sizeof(tcnt));
	memset(mcnt,0,sizeof(mcnt));
	
	n=read<int>();
	m=read<int>();
	for(register int i=1;i<=n*m;++i)
	{
		char c=gc();
		
		while(!islow(c)) c=gc();
		++tcnt[c-'a'];
	}
	
	for(register int i='a'-'a';i<='z'-'a';++i) ++mcnt[tcnt[i]%4];
	if(judge()) puts("Yes");
	else puts("No");
	
	return 0;
}
/*
1
2 2
aa
bb

5
3 4
aabb
aabb
aacc
2 2
aa
bb
5 1
t
w
e
e
t
2 5
abxba
abyba
1 1
z
*/