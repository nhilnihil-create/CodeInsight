#include<bits/stdc++.h>
#define F first
#define S second
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a>b? b:a)
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#define PICK(N,m,p) (N/(int)(pow(p,m-1))-(N/(int)(pow(p,m)))*p)
using lint = long long;
using ld = long double;
using namespace std;

//ユークリッド互除法
lint gcd(lint x,lint y){
    lint a=MAX(x,y);
    lint b=MIN(x,y);
    if(b==0) return a;
    else {
        lint q=a/b;
        lint g=gcd(b,a-q*b);
        return g;
    }
}

int main(){
    lint A, B, C;
    cin >> A >> B >> C;
    if(C%gcd(A,B)==0) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}