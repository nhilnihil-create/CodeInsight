#include<cstdio>
int a[25];

int getRes(){
    fflush(stdout);
    char s[2];
    scanf("%s",s);
    return s[0]=='Y';
}

int main(){
    int find = -1;
    for(int i = 0; i <= 11; i++){
        printf("? 1");
        for(int j = 1; j <= i; j++) printf("0");
        printf("\n");
        fflush(stdout);
        if(getRes()) continue;
        else{
            find = i;
            break;
        }
    }
    if(find==-1){
        int len = -1;
        for(int i = 1; i <= 11; i++){
            printf("?");
            for(int j = 1; j <= i; j++) printf("9");
            printf("\n");
            if(getRes()){
                len = i;
                break;
            }
        }
        printf("! 1");
        for(int i = 1; i <= len-1; i++) printf("0");
        printf("\n");
    }
    else{
        int len = find;
        for(int i = 1; i <= len; i++){
            int L = 0, R = 9;
            if(i==1) L++;
            int res = -1;
            while(L<=R){
                int M = (L+R)/2;
                printf("? ");
                for(int j = 1; j <= i-1; j++) printf("%d",a[j]);
                if(i==len) printf("%d1\n",M);
                else printf("%d\n",M);
                if(i!=len){
                    if(getRes()){
                        res = M;
                        L = M+1;
                    }
                    else R = M-1;
                }
                else{
                    if(getRes()){
                        res = M;
                        R = M-1;
                    }
                    else L = M+1;
                }
            }
            a[i] = res;
        }
        printf("! ");
        for(int i = 1; i <= len; i++) printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
