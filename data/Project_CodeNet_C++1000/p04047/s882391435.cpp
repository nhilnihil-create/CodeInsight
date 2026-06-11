#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 200+1       
using namespace std;
int n,a[maxn],ans;      
int main(){
    scanf("%d",&n);
    int md=n<<1;   
    for(int i=1;i<=md;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+md);     
    for(int i=1;i<=md;i+=2)ans+=a[i];
    printf("%d\n",ans);
    return 0;
}