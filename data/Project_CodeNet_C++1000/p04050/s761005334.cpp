#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int a[110];

int main(){
     
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0); 
        
	int n , m , ind = 0 , o = 0;
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++){
	   cin >> a[i];
	   if(a[i] % 2){		  
		  if(!o)
			 swap(a[i] , a[0]);
		  else
			 ind = i;
			 
		  o++;	
		}  
	}

	if(o > 2){
	  cout << "Impossible" << endl;
	  return 0;
	}
	
	swap(a[ind] , a[m-1]);

	for(int i = 0 ; i < m ; i++)
	   cout << a[i] << " ";
	
	cout << endl;

	int t = (a[0] == 1 ? m-1 : m);

	if(m == 1){

		if(n == 1)
		   cout << "1\n1" << endl;
		else  
		   cout << "2\n1 " << a[0] - 1 << endl;

	}
	else{
	   
	   cout << t << endl;
	   if(t == m)
		  cout << a[0] - 1 << " ";

	   for(int i = 1 ; i < m-1 ; i++)
		  cout << a[i] << " ";

		cout <<  a[m-1] + 1 << endl;
	}



	return 0;
}