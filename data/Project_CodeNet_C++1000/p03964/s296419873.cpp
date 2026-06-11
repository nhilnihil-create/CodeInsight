//do not think about past and stay in this moment
//organize and work - Abhinav IIITA
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define int long long
#define ld long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end() 
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



// -----------------------------------------------------------------------

int arr[3000000];
void input(int n){
	for(int i=0;i<n;++i)
	cin>>arr[i];
}

// -----------------------------------------------------------------------



void solve(){
	
    int n;
    cin>>n;
    n--;
    int l,r;
    cin>>l>>r;
    while(n--){
        int a,b;    cin>>a>>b;
        //let number be ax, bx;
        int a1=(l+a-1)/a;
        int a2=(r+b-1)/b;   // upper ceiled
        int x=max(a1,a2);
        l=a*x;
        r=b*x;
    }
    cout<<l+r;
}


// -----------------------------------------------------------------------


int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 	
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}
