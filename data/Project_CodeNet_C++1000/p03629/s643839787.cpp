#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
vector<int>b[26];
int n;
char c[200005];
int s[200005];
bool ok[26];
int main(void){
    scanf("%s",c);
    n=strlen(c);
    int k=0,l=1;
    for(int i=n-1;i>=0;i--){
        s[i]=l;
        int x=c[i]-'a';
        b[x].push_back(i);
        if(!ok[x]){
            ok[x]=true;
            if(++k==26){
                k=0;
                l++;
                for(int j=0;j<26;j++)ok[j]=false;
            }
        }
    }
    for(int i=0;i<26;i++){
        b[i].push_back(n);
        sort(b[i].begin(),b[i].end());
    }
    k=l;
    l=-1;
    for(int i=0;i<k;i++){
        for(int j=0;j<26;j++){
            if(s[*upper_bound(b[j].begin(),b[j].end(),l)]<k-i){
                l=*upper_bound(b[j].begin(),b[j].end(),l);
                printf("%c",char(j+'a'));
                break;
            }
        }
    }
    printf("\n");
}
