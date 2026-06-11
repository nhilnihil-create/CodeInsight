#include<bits/stdc++.h>

typedef  long long ll;
//forループ
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//
//
#define int long long

using namespace std;

int ctoi(char c) {
 switch (c) {
 case '0': return 0;
 case '1': return 1;
 case '2': return 2;
 case '3': return 3;
 case '4': return 4;
 case '5': return 5;
 case '6': return 6;
 case '7': return 7;
 case '8': return 8;
 case '9': return 9;
 default: return 0;
 }
}


 ll  a,b,c,s,t,i,j,k,x,y,z;
 ll A,B,C,S,T,X,Y,Z;
 ll count;
signed main(){
string L;
 cin >>  L;

 reverse(L.begin(),L.end());

i=L.size();
for(i;i>0;){
	if(L[0]=='m'&&L[1]=='a'&&L[2]=='e'&&L[3]=='r'&&L[4]=='d'){
		i=i-5;
		for(t=0;i>t;t++) L[t]=L[t+5];
	}
    if(L[0]=='e'&&L[1]=='s'&&L[2]=='a'&&L[3]=='r'&&L[4]=='e'){
    	i=i-5;
    	for(t=0;i>t;t++) L[t]=L[t+5];
    }
    if(L[0]=='r'&&L[1]=='e'&&L[2]=='s'&&L[3]=='a'&&L[4]=='r'&&L[5]=='e'){
    	i=i-6;
    	for(t=0;i>t;t++) L[t]=L[t+6];
    }
    if(L[0]=='r'&&L[1]=='e'&&L[2]=='m'&&L[3]=='a'&&L[4]=='e'&&L[5]=='r'&&L[6]=='d'){
    	i=i-7;
    	for(t=0;i>t;t++) L[t]=L[t+7];
    }
    if(!(L[0]=='m'&&L[1]=='a'&&L[2]=='e'&&L[3]=='r'&&L[4]=='d')
    &&!(L[0]=='e'&&L[1]=='s'&&L[2]=='a'&&L[3]=='r'&&L[4]=='e')
    &&!(L[0]=='r'&&L[1]=='e'&&L[2]=='s'&&L[3]=='a'&&L[4]=='r'&&L[5]=='e')
    &&!(L[0]=='r'&&L[1]=='e'&&L[2]=='m'&&L[3]=='a'&&L[4]=='e'&&L[5]=='r'&&L[6]=='d')
    || (0<i&&i<5)){
    	cout<<"NO";
    return 0;
    }
}
 cout<<  "YES"  <<endl;
  
 return 0;
}
