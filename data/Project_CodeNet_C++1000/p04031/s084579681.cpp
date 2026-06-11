#include <iostream>
#include <bits/stdc++.h>
#include <cmath>


using namespace std;



int main(){
	int t , temp;
	cin >> t;
	vector <int> a;
	for(int i=0;i<t;i++){
		cin >> temp;
		a.push_back(temp);	
}
sort(a.begin(),a.end());
int sum = INT_MAX;
	for(int i=a[0] ;i<=a[t-1];i++){
        int sum1 = 0;
		for(int j=0;j<t;j++){      
		  sum1 += pow(a[j] - i,2);
		}
        sum = min(sum,sum1);
		
}
cout << sum;

}

