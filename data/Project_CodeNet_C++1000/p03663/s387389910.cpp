//* AuThOr GaRyMr *//
//Codeforces ID: GaryMr Blue
//Atcoder ID: Gary Blue
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
bool check(LL x){
	cout<<"? "<<x<<endl;
	ff;
	char flag;
	cin>>flag;
	if(flag=='Y') return 1;
	else return 0;
}
int main(){
	char flag;
	int wei;
	wei=1;
	string s="1";
	rb(i,1,10) {
		cout<<"? "<<s<<endl;
		ff;
		cin>>flag;
		s+='0';
		if(flag=='N'){
			wei--;
			break;
		}
		wei++;
	}
	if(wei==11){
		string s1="2";
		wei=1;
		rb(i,1,10){
			cout<<"? "<<s1<<endl;
			ff;
			cin>>flag;
			if(flag=='Y'){
				break;
			}
			wei++;
			s1+='0'; 
		}
		cout<<"! 1";
		rep(i,wei-1){
			cout<<"0";
		}
		cout<<endl;
		return 0;
	}
	LL l=1,r;
	rb(i,1,wei-1) l*=10;
	r=l*10-1;
	while(l+2<r){
		LL mid=(l+r)>>1;
		if(check(mid*10)) r=mid+1;
		else l=mid;
	}
	for(LL i=l;i<=r;i++){
		if(check(i*10)) break;
		l++;
	} 
	cout<<"! "<<l<<endl;
	return 0;
}
