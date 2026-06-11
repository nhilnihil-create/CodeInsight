#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

int t[505][505];
priority_queue<P> q1;

int main(){
	int n;
	LL a,b,c,d;
	LL p,q;
	LL i;
	cin>>n>>a>>b>>c>>d;
	n--;
	a=abs(a-b);
	for(i=0;i<=n;i++){
		p=c*i-d*(n-i);
		q=d*i-c*(n-i);
		if(p<=a && a<=q)break;
	}
	print_YES_NO(i<=n);
}
