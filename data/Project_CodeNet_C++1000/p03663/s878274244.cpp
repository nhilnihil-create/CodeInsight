#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000
int N;
void Q(string s){
	cout<<"? "<<s<<endl;
}
void A(string s){
	cout<<"! "<<s<<endl;
	//if(stoi(s)==N)cout<<"Yes"<<endl;
}

char get(string x){
	char c;
	cin>>c;
	/*
	long long xx = stoll(x);
	string n = to_string(N);
	
	if(xx>N&&x>n)return 'Y';
	if(xx<=N&&x<=n)return 'Y';
	return 'N';
	*/
	return c;
}

int main(){
	//cin>>N;
	
	string S(18,'9');
	
	for(int i=0;i<9;i++){
		int ok = -1,ng = 10;
		if(i==0)ok=0;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			S[i] = mid+'0';
			Q(S);
			char c = get(S);
			if(c=='Y')ng=mid;
			else ok = mid;
		}
		S[i] = ok+1+'0';
	}
	for(int i=9;i<18;i++)S[i] = '0';
	
	
	while(S.back()=='0')S.pop_back();
	
	if(S=="1"){
		S[0] = '2';
		while(true){
			Q(S);
			char c = get(S);
			if(c=='Y'){
				S[0] = '1';
				break;
			}
			else{
				S.push_back('0');
			}
		}
	}
	else{
		string t = "1";
		while(true){
			Q(t);
			char c = get(t);
			if(c=='Y'){
				t.push_back('0');
			}
			else{
				
				while(S.size()+1!=t.size())S.push_back('0');
				break;
			}
		}
	}
	
	A(S);
			
	
	return 0;
}