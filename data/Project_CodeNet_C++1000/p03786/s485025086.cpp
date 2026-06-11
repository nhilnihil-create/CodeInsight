#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main(){
	long long n, a[100009];
  	cin >> n;
  	for(int i=0;i<n;i++)cin >> a[i];
  	sort(a, a+n);
  	int cnt=1;
  	long long sm=a[0];
  	for(int i=1;i<n;i++){
    	if(sm*2<a[i])cnt=0;
      	cnt++;
      	sm+=a[i];
    }
  	cout << cnt << endl;
}