#include<iostream>
#include<set>
#include <cstdio>
#include<vector>
#include<algorithm>
#define md 1000000007
#define ll long long

using namespace std;
	int n ;
int main(){
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
	scanf("%d", &x[i]);
    }
    ll res=1; int curpos= 0;
    for(int i=0; i<n; i++){
	if(x[i]<2*(i-curpos)+1){
	    res*=(i+1)-curpos; res%=md;
	    curpos++;
	}
    }
    for(int i=curpos; i<n;i++){
	res*=n-i; res%=md;
    }
    cout<<res<<"\n";
}