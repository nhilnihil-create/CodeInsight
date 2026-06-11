#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	Pi st,en,at;
	int ans=0;
	cin >>st.F>>st.S>>en.F>>en.S;
	at=st;
	P dis=mp(en.F-st.F,en.S-st.S);
	if(dis.F >0){
		rep(i,dis.F){
			cout<<"R";
		}
	}else{
		rep(i,-dis.F){
			cout<<"L";
		}
	}
	if(dis.S>0){
		rep(i, dis.S)
		{
			cout << "U";
		}
	}
	else
	{
		rep(i, -dis.S)
		{
			cout << "D";
		}
	}
	///---------------//
	if (dis.F > 0)
	{
		rep(i, dis.F)
		{
			cout << "L";
		}
	}
	else
	{
		rep(i, -dis.F)
		{
			cout << "R";
		}
	}
	if (dis.S > 0)
	{
		rep(i, dis.S)
		{
			cout << "D";
		}
	}
	else
	{
		rep(i, -dis.S)
		{
			cout << "U";
		}
	}
	//--------------hald-----------//
	if(dis.S >0){
		cout<<"D";
	}else{
		cout<<"U";
	}
	if (dis.F > 0)
	{	
		rep(i, dis.F+1)
		{
			cout << "R";
		}
	}
	else
	{
		rep(i, -dis.F+1)
		{
			cout << "L";
		}
	}
	if (dis.S > 0)
	{
		rep(i, dis.S+1)
		{
			cout << "U";
		}
	}
	else
	{
		rep(i, -dis.S+1)
		{
			cout << "D";
		}
	}
	if(dis.F>0){
		cout<<"L";
	}else{
		cout<<"R";
	}
	///---------------//
	if(dis.S >0){
		cout<<"U";
	}else{
		cout<<"D";
	}
	if (dis.F > 0)
	{
		rep(i, dis.F+1)
		{
			cout << "L";
		}
	}
	else
	{
		rep(i, -dis.F+1)
		{
			cout << "R";
		}
	}
	if (dis.S > 0)
	{
		rep(i, dis.S+1)
		{
			cout << "D";
		}
	}
	else
	{
		rep(i, -dis.S+1)
		{
			cout << "U";
		}
	}
	if(dis.F>0){
		cout<<"R"<<endl;
	}else{
		cout<<"L"<<endl;
	}
}