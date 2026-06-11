#include <bits/stdc++.h>

using namespace std;

#define ALL(c) c.begin(), c.end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define DB(a) cerr << #a << " = " << (a) << endl;
#define OUT( a , n ) for( int J = 0; J < (n); J++ )cout<< (a)[J] << " \n"[J == (n) - 1 ]
#define WAIT cout << flush , system("PAUSE");
#define lowbit(x) ((x) & (-x))
#define CONTAINS(a, x) ((a).find(x) != (a).end())
#define endl '\n'
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

typedef long long ll;

const int N = 1e6+100;

int n , k , p;

char s[15];
char ans[15];

bool test(){
	printf("? %s\n",s); fflush(stdout);
	scanf("%s", ans);
	return ans[0] == 'Y';
}

bool is_pow_10(ll x){
	while(x > 1){
		if(x % 10)return false;
		x /= 10;
	}
	return true;
}
bool checkend(int pos){
	long long num = 0;
	for( int i = 0; i <= pos; ++i){
		num = num * 10 + s[i] - '0';
	}

	int last_dig = num % 10;

	if(last_dig == 9){
		 long long other = num + 1;
		 printf("? %lld\n",other); fflush(stdout);
		 scanf("%s", ans);

		if(is_pow_10(other)){
			return ans[0] == 'N';
		}
		else{
			return ans[0] == 'Y';
		}
	}
	else{
		num++;
		printf("? %lld\n",num); fflush(stdout);
		scanf("%s", ans);
		return ans[0] == 'Y';
	}
}

int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	for( int i = 0; i < 14; i++ ){
		s[i] = '9';
	}


	for( int i = 0; i < 11; i++ ){
		s[i] = '1';

		int lo = i == 0 ? 1 : 0;
		int hi = 9;

		while(lo < hi){
			int mid = (lo + hi) / 2;
			s[i] = '0' + mid;
			if(test()){
				hi = mid;
			}
			else lo = mid + 1;
		}
		s[i] = '0' + lo;

		if(checkend(i)){
			s[i + 1] = 0;
			printf("! %s\n",s); fflush(stdout);

			exit(0);
		}

	}

    return 0;
}
