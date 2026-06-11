#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


ll sum(int n);

bool is_even(string s, int n) {
	string f1=s.substr(0,n/2);
	string f2=s.substr(n/2,n);
	return f1==f2;
}
void go(){
	string s;cin>>s;
	s.pop_back();
	int n=sz(s);
	
	while(!is_even(s, n)) {
		s.pop_back();
		n=sz(s);
	}
	cout << sz(s);
}
int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}

ll sum(int n){                
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
