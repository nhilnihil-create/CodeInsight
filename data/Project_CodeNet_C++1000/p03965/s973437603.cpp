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
	    
	string s;
	cin>>s;
	int p=0,r=0;
	int a=0;
	for(int i=0;i<sz(s);++i){
	    if(s[i]=='g'){
	        if(p==0 && r==0){
	            r++;   
	        }
	        else if(p<r){
	            p++;
	            a++;
	        }else{
	            r++;
	        }
	    }else{
	        if(p==0 && r==0){
	            r++;
	            a--;
	        }
	        else if(p<r){
	            p++;
	        }else{
	            r++;
	            a--;
	        }
	    }
    }
    cout<<a;
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
