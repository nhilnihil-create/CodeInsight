#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<complex>

using namespace std;


//ユークリッドの互除法　a,bは最大公約数を求めたい２つの数
long long int gcd(long long int a, long long int b) {
             long long int tmp;
             long long int r = 1;
             if (b > a) {
                           tmp = a;
                           a = b;
                           b = tmp;
             }
             r = a % b;
             while (r != 0) {
 
 
                           a = b;
                           b = r;
                           r = a % b;
 
             }
             return b;
}

const long long int mod=1000000007;
int main(){
	long long int n,m;
	string str[30][30];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cin>>str[i][j];

		if(str[i][j]=="snuke"){cout<<(char)(j+'A')<<i+1<<endl;}
		}
	}
	
}
