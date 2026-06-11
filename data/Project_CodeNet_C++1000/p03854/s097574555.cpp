#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

const string mode[4]={"dream","dreamer","erase","eraser"};

bool Match(const string&mo,const char* s,const int&k){
    int l=mo.length();
    for(int i=0;i<l;i++){
        if(mo[i]!=s[i+k]) return false;
    }
    return true;
}

void DFS(const int&k,const char* s,bool &F){
    if(k==strlen(s)){
        F=true;
        return;
    }
    for(int i=0;i<4;i++){
        if(Match(mode[i],s,k)){
            DFS(k+mode[i].length(),s,F);
            if(F) return;
        }
    }
}

int main(){
    char s[MAX];
    while(~scanf("%s",s)){
        bool F=false;
        DFS(0,s,F);
        if(F) puts("YES");
        else puts("NO");
    }
    return 0;
}
