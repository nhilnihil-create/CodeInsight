#include<iostream>
using namespace std;
long long n,now=0,good,targ=0,log2=0;
int a[205]={0};
void solution(long long good)
{
    int i=40, L=101,R=L-1;
    for(;!((1ll<<i)&good);i--);
    for(i--;i>=0;i--){
        a[++R]=++now;
        if((1ll<<i)&good) a[--L]=++now;
    }

    n=R-L+1;
    for(int i=1;i<=n;i++) a[i]=a[i+L-1];
    for(int i=n+1;i<=n*2;i++) a[i]=i-n;
    n<<=1;
}
int main()
{
    cin>>good;
    int tep=good+1;
    while(tep/2){
        log2++;
        tep/=2;
    }
    targ=log2;
    solution(good+1);
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
