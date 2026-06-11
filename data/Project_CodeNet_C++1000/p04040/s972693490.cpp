#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

long long x, y, mcd;

void extendedEuclid(long long a, long long b){
	if(b == 0){
		x = 1;
		y = 0;
		mcd = a;
	}
	else{
		extendedEuclid(b, a % b);
		x = y;
		y = (mcd - a*x) / b;
	}
}

// retorna (a/b) mod m
long long moduloDivision(long long a, long long b, long long modulo){
//	if(a % b != 0)
//	return -1;	// Division inexacta
	extendedEuclid(b,modulo);
	if(x < 0)
	x += modulo;
	return (x * (a / mcd)) % modulo;
}


const int maxN = 200000;
const long long mod = 1000000007;
vector<long long> V1(maxN+1), V2(maxN+1);

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long long H,W,A,B,i;
	long long x,y,k,ans;
	cin>>H>>W>>A>>B;
	x = B+1;
	V1[0] = 1;
	for(i=1,x=B+1,y=1; i<H; i++,x++,y++){
		V1[i] = (V1[i-1] * x) % mod;
		V1[i] = moduloDivision(V1[i], y, mod);
	}
	for(i=H-A; i<H; i++)
	V1[i] = V1[i-1];
	
	V2[H-1] = 1;
	for(i=H-2,x=W-B-1,y=1; i>=0; i--,x++,y++){
		V2[i] = (V2[i+1] * x) % mod;
		V2[i] = moduloDivision(V2[i], y, mod);
	}

	ans = 0;
	for(i=0; i<H; i++){
		k = (V1[i] * V2[i]) % mod;
		ans = (ans + k) % mod;
	}

//	for(i=0; i<H; i++){ cout<<V1[i]<<" "; }	cout<<endl;
//	for(i=0; i<H; i++){ cout<<V2[i]<<" "; }	cout<<endl;

	cout<<ans<<endl;
}