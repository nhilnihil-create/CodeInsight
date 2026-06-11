    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define sqr(x) ((x)*(x))
    #define mp make_pair
    #define uint unsigned
    #define PI pair<int,int>
    inline char gc(){
        static char buf[100000],*p1=buf,*p2=buf;
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    }
    #define gc getchar
    inline int read(){
    	int x = 0; char ch = gc(); bool positive = 1;
    	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    	return positive ? x : -x;
    }
    inline void write(ll a){
        if(a<0){
        	a=-a; putchar('-');
    	}
        if(a>=10)write(a/10);
        putchar('0'+a%10);
    }
    inline void writeln(ll a){
        if(a<0){
        	a=-a; putchar('-');
    	}
    	write(a); puts("");
    }
    inline int rnd(int x){
    	return (rand()<<16|rand())%x;
    }
    const int N=100005;
    ll k;
    int n,m,ans[N],q[N],a[N],que[N];
    ll dq[N];
    int main(){
    	n=read();
    	for(int i=1;i<=n;i++)a[i]=read();
    	for(int i=1;i<=n;i++)q[i]=i;
    	m=read(); cin>>k;
    	for(int i=1;i<=m;i++){
    		int pos=read();
    		swap(q[pos],q[pos+1]);
    	}
    	for(int i=1;i<=n;i++)if(!ans[i]){
    		que[0]=i; int jb=1;
    		for(int j=q[i];j!=i;j=q[j])que[jb++]=j;
    		for(int j=0;j<jb;j++)ans[que[j]]=que[(j+k%jb)%jb];
    	}
    	for(int i=1;i<=n;i++)dq[i]=a[ans[i]]-a[ans[i]-1];
    	for(int i=1;i<=n;i++)dq[i]+=dq[i-1];
    	for(int i=1;i<=n;i++)writeln(dq[i]);
    }
    /*
    1 2 3 4 5
    1 3 2 4 5
    1 3 4 2 5
    1 3 4 5 2
    */