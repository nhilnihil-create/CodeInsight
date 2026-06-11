#include"bits/stdc++.h"
using namespace std ;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define bug( x ,y) cerr << #x << '=' << x<<','<<#y<<'='<< y << '\n' ;


int n ,a,b;


int main(){

	IOS

	cin >> n >> a >>b;

	string s ;

	cin >> s;


	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='a' && (a>0 || b>0) ){

			cout << "Yes" << '\n';
			
			if(a>=0)a--;

            if(a==-1)b--;
            

		}

		else if(s[i] =='b' && b>0){

			cout << "Yes\n";

			if(b>0)b--;

		}

		else{
			cout << "No\n";
		}
	
	}




	
 
}