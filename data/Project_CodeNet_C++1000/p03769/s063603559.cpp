/*Program from Luvwgyx*/
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
deque<int >s1,s2;int n;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);putchar('\n');}
void Write(int x){print(x);putchar(' ');}
signed main(){
    int n=read()+1,digit=0,now=0;
    for(int i=1;i<=n;i<<=1)digit++;
    for(int i=digit-2;i>=0;i--){
        s1.push_back(++now);s2.push_back(now);
        if((n>>i)&1)s1.push_front(++now),s2.push_back(now);
    }write((int)s1.size()+(int)s2.size());
    deque<int > :: iterator it;
    for(it=s1.begin();it!=s1.end();it++)Write(*it);
    for(it=s2.begin();it!=s2.end();it++)Write(*it);
    puts("");
    return 0;
}
