#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline bool query(const LL& n) {
	printf("? %I64d\n",n);
	fflush(stdout);
	char ch=getchar();
	while (ch==' ' || ch=='\n') ch=getchar();
	return ch=='Y';
}

inline bool query(const char* s) {
	printf("? %s\n",s);
	fflush(stdout);
	char ch=getchar();
	while (ch==' ' || ch=='\n') ch=getchar();
	return ch=='Y';
}

inline int getlen() {
	int l=1,r=10;
	while (l<r) {
		int mid=(l+r+1)/2;
		LL x=1;
		for (int i=1;i<mid;++i) x=x*10;
		bool f=query(x);
		if (!f) r=mid-1;else l=mid;
	}
	return l;
}

inline LL getnum(const int& len) {
	char str[20];
	for (int i=0;i<len+3;++i) str[i]=0;
	for (int i=0;i<len-1;++i) {
		int l=0,r=9;
		while (l<r) {
			int mid=(l+r+1)/2;
			str[i]='0'+mid;
			bool f=query(str);
			if (!f) r=mid-1;else l=mid;
		}
		str[i]='0'+l;
	}
	str[len]='0';
	int l=0,r=9;
	while (l<r){
		int mid=(l+r)/2;
		str[len-1]='0'+mid;
		bool f=query(str);
		if (!f) l=mid+1;else r=mid;
	}
	str[len-1]='0'+l;
	str[len]=0;
	return atoi(str);
}

inline LL prefix_special() {
	const int MaxLen = 10;
	char str[MaxLen+3];
	for (int i=0;i<MaxLen;++i) str[i]='9';
	int l=0,r=10;
	while (l<r) {
		int mid=(l+r+1)/2;
		str[mid]=0;
		bool f=query(str);
		str[mid]='9';
		if (f) r=mid-1;else l=mid;
	}
	LL x=1;
	for (int i=1;i<=l;++i) x*=10;
	return x;
}

int main() {
	LL ans;
	if (query(100000000000LL)) {
		ans=prefix_special();
	} else {
		int len=getlen();
		ans=getnum(len);
	}
	printf("! %I64d\n",ans);
	return 0;
}