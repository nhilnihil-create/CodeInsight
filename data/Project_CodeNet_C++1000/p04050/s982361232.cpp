#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101;
int n , m , sum = 0;
int a[MAXN] , b[MAXN * 10];
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; ++ i)
		cin >> a[i];
	if(m == 1){
		if(a[1] == 1)
			cout << 1 << endl << 1 << endl << 1 << endl;
		else
			cout << a[1] << endl << 2 << endl << a[1] - 1 << " " << 1 << endl; 
		return 0;
	}
	for(int i = 2 ; i < m ; ++ i)
		if(a[i] & 1)
			swap(a[1] , a[i]);
	for(int i = 2 ; i < m ; ++ i)
		if(a[i] & 1)
			swap(a[i] , a[m]);
	for(int i = 2 ; i < m ; ++ i)
		if(a[i] & 1){
			cout << "Impossible" << endl;
			return 0;
		}
	if(a[1] & 1){
		if(a[1] > 1)
			b[++ sum] = a[1] - 1;
	}
	else{
		if(a[1] == 2)
			b[++ sum] = 1;
		else{
			b[++ sum] = a[1] - 2;
			b[++ sum] = 1;
		}
	}
	for(int i = 2 ; i < m ; ++ i)
		b[++ sum] = a[i];
	b[++ sum] = a[m] + 1;
	for(int i = 1 ; i <= m ; ++ i)
		cout << a[i] << " ";
	cout << endl;
	cout << sum << endl;
	for(int i = 1 ; i <= sum ; ++ i)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}