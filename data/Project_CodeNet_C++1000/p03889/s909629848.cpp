#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	register short f=1;x=0;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
template<typename T>inline void writeln(T x){
	write(x),putchar('\n');
}
int main(){
	string str,s;cin>>str;
	s=str;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		switch(s[i]){
			case 'b':s[i]='d';break;
			case 'd':s[i]='b';break;
			case 'p':s[i]='q';break;
			case 'q':s[i]='p';break;
		}
	}
	if(s==str)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
