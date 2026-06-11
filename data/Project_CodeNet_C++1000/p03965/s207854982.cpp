#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int N;
string s;
int cnt_g,cnt_p;
int main(){
    cin>>s;
    N = s.length();
    cnt_g=0;cnt_p=0;
    int ans=0;
    for(int i=0;i<N;i++){
        if(cnt_g==cnt_p){
            ++cnt_g;
            if(s[i]=='p') --ans;
        }
        else {
            ++cnt_p;
            if(s[i]=='g')  ++ans;
        }
    }
    printf("%d\n",ans);
    getchar();
    getchar();

    return 0;

}