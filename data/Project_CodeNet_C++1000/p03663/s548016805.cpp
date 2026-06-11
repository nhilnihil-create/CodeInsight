#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

int val=0;
int cnt=0;

/*
void rt(int n)
{
	cnt=0;
	val=n;
}
*/
int query(int64 n)
{
#ifdef _MSC_VER
	++cnt;
	//printf("cnt = %d  q = %lld\n",cnt,n);
	if (n<=val && to_string(n)<=to_string(val)) return 1;
	if (n>val && to_string(n)>to_string(val)) return 1;
	return 0;
#else
	cout<<"? "<<n<<endl;
	cout.flush();
	string s;
	cin>>s;
	return (int)(s[0]=='Y');
#endif
}
int query(string s)
{
	return query(atoll(s.c_str()));
}

void answer(int n)
{
#ifdef _MSC_VER
	printf("ans = %d  cnt = %d  ",n,cnt);
	printf("actual = %d\n",val);
	if (cnt>60 || n!=val)
	{
		printf("WA!!!!!!!!!!!!!!!!\n");
		exit(0);
	}
	else
		printf("PASS\n");
#else
	cout<<"! "<<n<<endl;
	cout.flush();
#endif
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	//rt(100000000);
	//for (int m=1;m<=1000000;m++) { rt(m);
	std::ios::sync_with_stdio(false);
	string s="";
	const int L=11;
	REP(i,L)
	{
		int low=0,high=10;
		if (s=="") low=1;
		for (;low+1<high;)
		{
			int mid=(low+high)/2;
			string t=s;
			t+=char('0'+mid);
			REP(j,L-i) t+='0';
			if (query(t))
				high=mid;
			else
				low=mid;
		}
		s+=(char)('0'+low);
	}
	if (s=="10000000000")
	{
		string t="1";
		while (1)
		{
			string w=to_string(atoll(t.c_str())+1);
			if (query(w)) break;
			t+='0';
		}
		answer(atoll(t.c_str()));
	}
	else
	{
		s=to_string(atoll(s.c_str())+1);
		string t=s;
		while (LENGTH(t)>0 && t[LENGTH(t)-1]=='0') t=t.substr(0,LENGTH(t)-1);
		bool all9=true;
		REP(i,LENGTH(t)) if (t[i]!='9') all9=false;
		if (all9)
		{
			string w=to_string(atoll(t.c_str())+1);
			if (!query(w))
				answer(atoll(t.c_str()));
			else
			{
				t+='0';
				while (1)
				{
					string w=to_string(atoll(t.c_str())+1);
					if (query(w)) break;
					t+='0';
				}
				answer(atoll(t.c_str()));
			}
		}
		else
		{
			while (1)
			{
				string w=to_string(atoll(t.c_str())+1);
				if (query(w)) break;
				t+='0';
			}
			answer(atoll(t.c_str()));
		}
	}
	//}
	return 0;
}

