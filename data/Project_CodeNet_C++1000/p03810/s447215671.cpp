#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a, b) for(int i=a;i<b;++i)
#define pb push_back
/////////////////////////////////////

int const N = 1e5 + 41;

string ans[2] = {"First", "Second"};

int n;
vector<int> a;

int gcd(int a, int b){
	if(!a){
		return b;
	}
	return gcd(b%a, a);
}

int gcdV(vector<int> &v){
	int ret = v[0];
	fi(1, sz(v)){
		ret = gcd(ret, v[i]);
	}
	return ret;
}

void divideV(vector<int> &v, int d){
	fi(0, sz(v)){
		v[i] /= d;
	}
}

int cntOdd(vector<int> &v){
	int ret = 0;
	fi(0, sz(v)){
		if(v[i] % 2 == 1){
			++ret;
		}
	}
	return ret;
}

int cntEven(vector<int> &v){
	return sz(v) - cntOdd(v);
}

int getOddPos(vector<int> &v){
	fi(0, sz(v)){
		if(v[i] % 2 == 1){
			return i;
		}
	}
}

int cntOne(vector<int> &v){
	int ret = 0;
	fi(0, sz(v)){
		if(v[i] == 1){
			++ret;
		}
	}
	return ret;
}

long long getSum(vector<int> &v){
	long long ret = 0;
	fi(0, sz(v)){
		ret += v[i];
	}
	return ret;
}

void ok(int move){
	printf("%s\n",ans[move].c_str());
	exit(0);
}

void solve(){
	if(n == 1){
		if(a[0] == 1){
			ok(1);
		}else{
			ok(0);
		}
	}
	int move = 0;
	while(true){
		if(cntEven(a) == 0){
			ok(move ^ 1);
		}
		if(cntOne(a) > 0){
			if((getSum(a) - n) % 2 == 1){
				ok(move);
			}else{
				ok(move ^ 1);
			}
		}
		if(cntOdd(a) > 1){
			if(cntEven(a) % 2 == 1){
				ok(move);
			}else{
				ok(move ^ 1);
			}
		}else{
			--a[getOddPos(a)];
			divideV(a, gcdV(a));
		}
		move ^= 1;
	}
}

void read(){
	scanf("%d",&n);
	fi(0, n){
		int v;
		scanf("%d",&v);
		a.pb(v);
	}
}

void prepare(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

int main(){
	prepare();
	read();
	solve();


	return 0;
}