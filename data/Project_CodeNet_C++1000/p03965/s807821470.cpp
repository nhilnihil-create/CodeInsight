#include<bits/stdc++.h>
char c[100005];
int main(void){
    std::cin>>c;
	int l=strlen(c),qwq=0;
    for(int i=0;i<l;++i) if(c[i]=='g') qwq++;
    printf("%d\n\r",std::min(l/2,qwq)-std::min(l-l/2,l-qwq));
}