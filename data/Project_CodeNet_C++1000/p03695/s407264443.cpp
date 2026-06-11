#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}







int main() {
  int n;
  cin >> n;
  int a[n+1];
  rep (i,n){
    cin >> a[i];
  }
  int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,sum;
  rep (i,n){
    if (a[i]<400&&c1==0) c1++;
    if (a[i]>=400&&a[i]<800&&c2==0) c2++;
    if (a[i]>=800&&a[i]<1200&&c3==0) c3++;
    if (a[i]>=1200&&a[i]<1600&&c4==0) c4++;
    if (a[i]>=1600&&a[i]<2000&&c5==0) c5++;
    if (a[i]>=2000&&a[i]<2400&&c6==0) c6++;
    if (a[i]>=2400&&a[i]<2800&&c7==0) c7++;
    if (a[i]>=2800&&a[i]<3200&&c8==0) c8++;
    if (a[i]>=3200) c9++;
    sum = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8;
  }
  if (c9&&sum) cout << sum << " " << sum+c9 << endl;
  else if (sum==0&&c9) cout << 1 << " " << c9 << endl;
  else cout << sum << " " << sum << endl;

}