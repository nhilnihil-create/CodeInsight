#include<bits/stdc++.h>
using namespace std;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int read() {
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
int main(){
    char c[10];cin>>c;
    cout<<((c[0]!='Y' || c[1]!='A' || c[2]!='K' || c[3]!='I')?"No\n":"Yes\n");
    return 0;
}