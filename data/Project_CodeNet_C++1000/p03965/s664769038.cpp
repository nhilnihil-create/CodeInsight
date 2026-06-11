#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    string s; cin >> s;
  	int n = s.size();
  	int a = 0; int b = 0;
  	for(auto u:s){
    	if(u=='g'){
          a++;
        }
      	else{
          b++;
        }
        
    }
  	cout << (a-b)/2;
    
 
    return 0;
}
