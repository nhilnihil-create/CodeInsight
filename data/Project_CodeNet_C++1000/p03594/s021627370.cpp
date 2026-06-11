#include<cstdio>
using namespace std;
char s[]={'R','Y','G','B'};
int h,w,d;
int main(){
    scanf("%d%d%d",&h,&w,&d);
    for (int i=1;i<=h;++i){
        for (int j=1;j<=w;++j){
            int x=i+j+w,y=i-j+w;
            printf("%c",s[((x/d)&1)*2+((y/d)&1)]);
        }
        printf("\n");
    }
    return 0;
}