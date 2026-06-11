#include<cstdio>
using namespace std;
int main(){
    int n;
    long a,mini=1,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&a);
        ans+=(a-1)/mini;
        if(a==mini||mini==1){
            mini++;
        }
    }
    printf("%ld\n",ans);
}