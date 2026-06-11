#include<cstdio>
using namespace std;

int main(){
    char str[100005];
    while(~scanf("%s",str)){
        int ans=0;
        for(int i=1;str[i];i++){
            ans+=str[i]!=str[i-1];
        }
        printf("%d\n",ans);
    }
    return 0;
}
