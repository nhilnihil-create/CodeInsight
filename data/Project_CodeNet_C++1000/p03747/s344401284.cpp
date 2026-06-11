#include<cstdio>
#include<algorithm>
const int MaxN=100010;
int N,L,T,X[MaxN],W[MaxN],mem[MaxN],*list[2],cnt[2],end[MaxN];
bool cmp(int i,int j){
	return end[i]<end[j]||end[i]==end[j]&&W[i]>W[j];
}
void csort(int*l,int*r){
	int*i=l+1;
	while(i<r&&end[i[-1]]<end[*i])i++;
	if(i<r)std::inplace_merge(l,i,r,cmp);
}
long long dis(int w,int i,int d){
	long long t1=d/cnt[w]*1ll*L,t2;
	d%=cnt[w];
	int j=w?(i+d)%cnt[w]:(i-d+cnt[w])%cnt[w];
	t2=X[list[w][i]]-X[list[w][j]];
	if(w)t2=-t2;
	if(t2<0)t2+=L;
	return t1+t2;
}
int main(){
	scanf("%d%d%d",&N,&L,&T);
	list[0]=list[1]=mem;
	for(int i=0;i<N;i++){
		scanf("%d%d",X+i,W+i);
		if(!--W[i])list[1]++;
	}
	for(int i=0;i<N;i++){
		int w=W[i];
		list[w][cnt[w]++]=i;
		end[i]=w?((X[i]-T)%L+L)%L:(X[i]+T)%L;
	}
	for(int w=0;w<2;w++)if(!cnt[w]){
		for(int i=0;i<N;i++)printf("%d\n",end[i]);
		return 0;
	}
	int st=**list,pos=-1,md=L;
	for(int i=0;i<cnt[1];i++){
		int x=X[list[1][i]],d=(x-X[st])%L;
		if(d<0)d+=L;
		if(d<md)pos=i,md=d;
	}
	long long left=0,right=T*2ll+1,mid;
	while(right-left>1){
		mid=left+right>>1;
		int c0=mid/2,c1=(mid+1)/2-1;
		long long t=dis(0,0,c0)+md+dis(1,pos,c1);
		if(t<=T*2ll)left=mid;
		else right=mid;
	}
	int ty=left%2,cur=list[ty][ty?(pos+left/2)%cnt[1]:(cnt[0]-left/2%cnt[0])%cnt[0]],i=0;
	csort(mem,list[1]);
	csort(list[1],mem+N);
	std::inplace_merge(mem,list[1],mem+N,cmp);
	while(i<N&&mem[i]!=cur)i++;
	i=(i-st+N)%N;
	for(int j=0;j<N;j++)printf("%d\n",end[mem[(i+j)%N]]);
}