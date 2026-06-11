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
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

const int N=200005;
queue<int> uft_q1;
int uft_parent[2][N];
int uft_num[2][N];

int uft_check_parent(int mode,int uft_x){
	if(uft_parent[mode][uft_x]!=-1)return uft_check_parent(mode,uft_parent[mode][uft_x]);
	int uft_a;
	while(!uft_q1.empty()){
		uft_a=uft_q1.front(),uft_q1.pop();
		uft_parent[mode][uft_a]=uft_x;
	}
	return uft_x;
}

bool uft_connect(int mode,int uft_x,int uft_y){
	uft_x=uft_check_parent(mode,uft_x),uft_y=uft_check_parent(mode,uft_y);
	if(uft_x==uft_y)return true;
	if(uft_num[uft_x]>uft_num[uft_y])swap(uft_x,uft_y);
	uft_parent[mode][uft_x]=uft_y;
	uft_num[mode][uft_y]+=uft_num[mode][uft_x];
	return false;
}

map<LL,int> m1;
int s[N];

int main(){
	int n,m,p;
	int i,j,k;
	LL a,b,c;
	int z[5];
	memset(uft_parent,-1,sizeof(uft_parent));
	cin>>n>>z[0]>>z[1];
	for(i=0;i<2;i++){
		for(j=0;j<z[i];j++){
			cin>>a>>b;
			a--,b--;
			uft_connect(i,a,b);
		}
	}
	for(i=0;i<n;i++){
		a=(LL)uft_check_parent(0,i)*n+uft_check_parent(1,i);
		m1[a]++;
	}
	for(i=0;i<n;i++){
		a=(LL)uft_check_parent(0,i)*n+uft_check_parent(1,i);
		s[i]=m1[a];
	}
	array_show(s,n);
}