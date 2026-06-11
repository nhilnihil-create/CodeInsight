#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x;
	cin >> x;
	int i, j, p, m;
	for(i = 0; i <x.size(); i++){
		if(x[i] == 'A'){
			p = i;break;
		}
	}
	for(j = (x.size()-1) ; j >= 0; j--){
		if(x[j] == 'Z'){
			m = j; break;
		}
	}
	cout << m - p+1 << endl;
	
    return 0;
}