//copy from https://www.cnblogs.com/AKMer/p/10043220.html
#include <deque>
#include <cstdio>
using namespace std;
typedef long long ll;

int m,num;
deque<int> s1,s2;
deque<int>::iterator it;

ll read() {
    ll x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}

int main() {
    ll n=read()+1;//以为空串也是好串，所以这里要加一
    for(ll i=1;i<=n;i<<=1)m++;
    for(int i=m-2;~i;i--) {//初始有一个空串是好串，m-2是n的第二高的二进制位
        s1.push_back(++num),s2.push_back(num);
        if((n>>i)&1)s1.push_front(++num),s2.push_back(num);
    }
    printf("%d\n",(int)(s1.size()+s2.size()));
    for(it=s1.begin();it!=s1.end();it++)
        printf("%d ",(*it));
    for(it=s2.begin();it!=s2.end();it++)
        printf("%d ",(*it));
    return 0;
}