#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
 
#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
typedef long long ll;
using namespace std;

int n,a[300][300];
ll ans;
bool gb[300][300];

int main(){
	cin>>n;
	lp(n)
		LP(n,j){
			cin>>a[i][j];
			gb[i][j]=true;
		}
	lp(n){
		LP(n,j){
			if(j!=i)
				LP(n,k){
					if(k!=j&&k!=i){
						if(a[i][k]+a[k][j]<a[i][j]){
							cout<<-1<<endl;
							return 0;
						}
						if(a[i][k]+a[k][j]==a[i][j])
							gb[i][j]=false;
					}
				}
		}
	}
	ans=0;
	lp(n)
		LP(n,j)
			if(gb[i][j])
				ans+=a[i][j];
	cout<<ans/2<<endl;
	return 0;
}
