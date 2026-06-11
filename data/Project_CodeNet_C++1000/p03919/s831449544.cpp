#include<cstdio>
int main(){
    int h,w;
    char s[6], t[6]="snuke";
    scanf("%d%d",&h,&w);
    for(int i=0;i<h*w;i++){
        scanf("%s",s);
        int j;
        for(j=0;j<5;j++){
            if(s[j]!=t[j])break;
        }
        if(j==5){
            printf("%c%d",'A'+(i%w),i/w+1);
            return 0;
        }
    }
    return 0;
}