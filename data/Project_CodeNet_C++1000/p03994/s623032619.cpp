#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

ll alph(char x){
	if (x=='a') return 0;
	else if (x=='b') return 1;
	else if (x=='c') return 2;
	else if (x=='d') return 3;
	else if (x=='e') return 4;
	else if (x=='f') return 5;
	else if (x=='g') return 6;
	else if (x=='h') return 7;
	else if (x=='i') return 8;
	else if (x=='j') return 9;
	else if (x=='k') return 10;
	else if (x=='l') return 11;
	else if (x=='m') return 12;
	else if (x=='n') return 13;
	else if (x=='o') return 14;
	else if (x=='p') return 15;
	else if (x=='q') return 16;
	else if (x=='r') return 17;
	else if (x=='s') return 18;
	else if (x=='t') return 19;
	else if (x=='u') return 20;
	else if (x=='v') return 21;
	else if (x=='w') return 22;
	else if (x=='x') return 23;
	else if (x=='y') return 24;
	else if (x=='z') return 25;
	else return 100;
}

char ralp(ll x){
	if (x==0) return 'a';
	else if (x==1) return 'b';
	else if (x==2) return 'c';
	else if (x==3) return 'd';
	else if (x==4) return 'e';
	else if (x==5) return 'f';
	else if (x==6) return 'g';
	else if (x==7) return 'h';
	else if (x==8) return 'i';
	else if (x==9) return 'j';
	else if (x==10) return 'k';
	else if (x==11) return 'l';
	else if (x==12) return 'm';
	else if (x==13) return 'n';
	else if (x==14) return 'o';
	else if (x==15) return 'p';
	else if (x==16) return 'q';
	else if (x==17) return 'r';
	else if (x==18) return 's';
	else if (x==19) return 't';
	else if (x==20) return 'u';
	else if (x==21) return 'v';
	else if (x==22) return 'w';
	else if (x==23) return 'x';
	else if (x==24) return 'y';
	else if (x==25) return 'z';
	else return '-';
}


int main(){
	string s; cin >> s;
	ll k; cin >> k;
	vector<ll> indl;
	REP(i,s.size()){
		ll y = alph(s[i]);
		if (y!=0 && k>=26-y) {
			indl.pb(0);
			k -= 26-y;
		}
		else {
			indl.pb(alph(s[i]));
		}
	}
	k %= 26;
	ll ind = s.size();
	while (k>0){
		indl[ind-1]++;
		k--;
	}
	REP(i,s.size()){
		cout << ralp(indl[i]);
	}
	cout << endl;
}