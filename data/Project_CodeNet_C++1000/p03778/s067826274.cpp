#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define check cin >>
#define say cout <<
#define nicely << endl
#define initialize_playboy_mode ios_base::sync_with_stdio(0);
#define breakup_with_gf cin.tie(0);
#define messed_up cout << -1 << endl;
#define wife first
#define spare second

#define mgod main
#define wan 1

typedef int single;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

class Riajuu
{
	public:
	
	vector<int> girls;
	int testcount=1;
	
	void hears(int &x)
	{
		cin>>x; 
	}
	void count_girls()
	{
		cin>>testcount;
	}
	bool stillRiajuu()
	{
		girls.clear();
		testcount--;
		if(testcount>=0) return true;
		else return false;
	}
	void remove_girls()
	{
		girls.clear();
	}
	void check_girls(int x){
		for(int i=0;i<x;i++){
			int j; cin >> j;
			girls.push_back(j);
		}
	}
} MGod;

void flirt() {
    single w,a,b; cin >> w >> a >> b;
    if(a>b) swap(a,b);
    cout << max(0,b-a-w);
    return;
}

single mgod() {
    initialize_playboy_mode;
    breakup_with_gf;
    //MGod.count_girls();
    while(MGod.stillRiajuu()) flirt();
}
