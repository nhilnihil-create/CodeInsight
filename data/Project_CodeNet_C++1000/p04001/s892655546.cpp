#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int s[12];

long long int ans=0;
string x;
//先頭からi番目までの数字で,最後に＋を入れた後の数がwであるとする
//このvoidでの処理は、「自分(=i+1番目の数字)より前に＋を入れるかどうか」
void wf(int i,long long int ss,long long int w)
{
 //＋を入れたらssにwを足してwはs[i]で更新する
 //＋を入れなかったらssには何も足さずwを10*w+s[i]で更新する
 //もしiがx.size()に一致していたらwfには入れずにansにssを足してループを抜ける
 if((i+1)!=x.size())
	{
 	 wf(i+1,ss+w,s[i]); //＋を入れた処理
	 wf(i+1,ss,10*w+s[i]); //＋を入れない処理
	}
 if((i+1)==x.size())
	{
	 ans=ans+ss+w+s[i];//＋を入れた処理
	 ans=ans+ss+(10*w+s[i]);//＋を入れない処理
	}
}

int main()
{
 cin>>x;
 for(int i=0;i<x.size();i++)
 {
	s[i]=x[i]-'0';
 }
 //初期入力ではi=1,w=s[0]、x.size()==1なら除外してvoidには入れずにans=s[0]
 if(x.size()==1){ans=s[0];}
 else{wf(1,0,s[0]);}
 printf("%lld",ans);\
 
}