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
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return (rand()<<16|rand())%x;
}
ll n;
deque<int> fro,bac;
void solve(ll n,int id){
	if(n==1)return; 
	if(n&1){
		solve(n-1,id+1); fro.push_front(id); bac.push_back(id);
	}else{
		solve(n>>1,id+1); fro.push_back(id);  bac.push_back(id);
	}
}

int main(){
	cin>>n; n++;
	solve(n,1);
	cout<<fro.size()*2<<endl;
	while(fro.size()){
		cout<<fro.front()<<" "; fro.pop_front();
	}
	while(bac.size()){
		cout<<bac.front()<<" "; bac.pop_front();
	}
}