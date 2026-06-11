#include <bits/stdc++.h>

using namespace std;

struct w{
	int num;
	bool flag;
};

int q_sort(w d[],int left,int right){
	if(left >= right) return 0;
	int l = left, r = right;
	w pipot = d[(left+right)/2];
	w tmp;
	while(l<r){
		while(d[l].num < pipot.num) l++;
		while(d[r].num > pipot.num) r--;
		if( l <=  r){
			tmp = d[l];
			d[l] = d[r];
			d[r] = tmp;
			l++;
			r--;
		}
	}
	q_sort(d,left,r);
	q_sort(d,l,right);
}

int main(void)
{
	int n; cin>>n;
	w k[n]; 
	for(int i = 0; i < n; i++){
		int a;
		cin>>a;
		k[i].num = a;
		if(i%2 == 0) k[i].flag = false;
		else k[i].flag = true;
	}
	
	q_sort(k,0,n-1);
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i%2 == 0 && k[i].flag == true) ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}

