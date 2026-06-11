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
int mod;
void fx(vector<int> &a,int n, int m){

}

// -----------------------------------------------------------------------

int arr[3000000];
void input(int n){
	for(int i=0;i<n;++i)
	cin>>arr[i];
}

// -----------------------------------------------------------------------



void q1(){
	int n;
	cin>>n;
	n*=(n+1);
	n/=2;
	cout<<n;
}
// -----------------------------------------------------------------------


void q2(){
	string s,t;
	cin>>s;
	t="";
	int skip=0;
	for(int i=(int)s.size()-1;i>=0;i--){
		if(s[i]=='B'){
			skip++;
		} else{
			if(skip>0){
				skip--;
			} else{
				t+=s[i];
			}
		}
	}
	for(int i=sz(t)-1;i>=0;--i)
	cout<<t[i];
}

// -----------------------------------------------------------------------

void q3(){
	int n;
	cin>>n;
	input(n);
	ld sum=0;
	for(int i=0;i<n;++i){
		sum+=arr[i];
	}
	sum/=n;
	int l=sum;
	sum+=1.00;
	int u=sum;
	int pp,p;
	pp=0;
	sum=l;
	for(int i=0;i<n;++i){
		pp+=((arr[i]-sum)*(arr[i]-sum));
	}p=0;sum=u;
	for(int i=0;i<n;++i){
		p+=((arr[i]-sum)*(arr[i]-sum));
	}
	cout<<min(p,pp);
}


// -----------------------------------------------------------------------

void q4(){
	string s;
	cin>>s;
	int xp=sz(s);
	for(int i=0;i<xp-2;++i){
		if(s[i]==s[i+1]){
			cout<<i+1<<" "<<i+2<<endl;
			return ;
		}
		if(s[i]==s[i+2]){
			cout<<i+1<<" "<<i+3<<endl;
			return ;
		}
	}
	if(s[xp-1]==s[xp-2]){
		cout<<xp-1<<" "<<xp<<endl;
		return ;
	}
	cout<<"-1 -1\n";
	return ;
}

// -----------------------------------------------------------------------


int32_t main()
{
	mod=1e+7;
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 	
	int t=1;
	//cin>>t;
	while(t--)
	q4();
	return 0;
}
