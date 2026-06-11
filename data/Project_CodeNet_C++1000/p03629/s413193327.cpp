#include<cstdio>
#include<cstring>
char s[200005];
int f[200005];
int next[200005][27];
int pos[27];
char t[200005];

void preWork(int n){
    for(int i = 0; i < 26; i++) pos[i] = -1;
    for(int i = n; i >= 0; i--){
        for(int j = 0; j < 26; j++) next[i][j] = pos[j];
        if(i!=0) pos[s[i]-'a'] = i;
    }
}

int min(int a,int b){ return a>b?b:a; }

void getAnswer(int p,int size){
    if(f[p]==0){
        int find = -1;
        for(int i = 0; i < 26; i++){
            if(next[p][i]==-1){
                find = i;
                break;
            }
        }
        t[size] = find+'a';
    }
    else{
        int find = -1;
        for(int i = 0; i < 26; i++){
            int np = next[p][i];
            if(f[np]+1==f[p]){
                find = i;
                break;
            }
        }
        t[size] = find+'a';
        getAnswer(next[p][find],size+1);
    }
}

int main(){
    scanf("%s",s+1);
    int n = strlen(s+1);
    preWork(n);
    for(int i = n; i >= 0; i--){
        int ok = 1, minn = 1e7+7;
        for(int j = 0; j < 26; j++){
            if(next[i][j]==-1){
                ok = 0;
                break;
            }
            else minn = min(minn,f[next[i][j]]);
        }
        if(!ok) f[i] = 0;
        else f[i] = minn+1;
    }
    int ans = f[0]+1;
    //printf("%d\n",ans);
    getAnswer(0,1);
    for(int i = 1; i <= ans; i++) printf("%c",t[i]);
    printf("\n");
    return 0;
}
