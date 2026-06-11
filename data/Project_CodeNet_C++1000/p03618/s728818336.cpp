// 2020/05/25 2:16　開始
// 2020/05/25 3:39　部分文字列の回文の数を数えてそれを引けばいいかと思ったら違った。(Manacherの証明がよく分からないまま実装した。)
// 解説要約　S_i!=S_jのiとjの組み合わせの総数+1を数える。(i!=jの組み合わせ数からS_i==S_jの数を引いて1を足す。)
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string S;
    cin>>S;
    long long int ans=S.size()*(S.size()-1)/2+1;
    long long int num[30]={0};
    for(int i=0;i<S.size();i++)num[S[i]-'a']++;
    for(int i=0;i<30;i++)ans-=num[i]*(num[i]-1)/2;
    cout<<ans<<endl;
    /*
    string S2,S1;
    int ma[400009]={0};
    char S[400009];
    cin>>S2;
    S1=" "+S2;
    long long int ans=S2.size()*(S2.size()-1)/2+1;
    int pp=0;
    for(int i=0;i<S2.size();i++){
        if(i==0){
            S[pp]=' ';
            pp++;
        }
        S[pp]=S2[i];
        pp++;
        S[pp]='1';
        pp++;
        if(i==S2.size()-1){
            S[pp]='1';
            pp++;
        }
    }
    int jj=0;
    int kk=1;
    for(int i=1;i<pp;){
        for(jj;;jj++){
            if(S[i-jj]!=S[i+jj]){
                ma[i]=jj-1;
                break;
            }
        }
        for(kk=1;;kk++){
            if(ma[i-kk]<ma[i]-kk){
                ma[i+kk]=ma[i-kk];
            }
            else{
                break;
            }
        }
        i=i+kk;
        jj=max(jj-kk,0);
    }

    for(int i=0;i<20;i++){
        printf(" %c ",S[i]);
    }
    puts("");
    for(int i=0;i<20;i++){
        printf("[%d]",ma[i]);
    }

    for(int i=1;i<400009;i+=2){
        ans-=ma[i]/2;
        //printf("[%d]",ma[i]/2);
    }
    //puts("");
    for(int i=2;i<400009;i+=2){
        ans-=(ma[i]+1)/2;
        //printf("[%d]",ma[i]/2);
    }
    cout<<ans<<endl;
    */
    return 0;
}
