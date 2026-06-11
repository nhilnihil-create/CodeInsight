#include<bits/stdc++.h>
using namespace std;
long long INF;
int main(){
	long long h,w;
	cin>>h>>w;
	INF = w*h;
	long long r[4];
	for(int i=0; i<4; i++) r[i] = INF;
	
	if(h%3) r[0] = w;
	else r[0] = 0;
	if(w%3) r[1] = h;
	else r[1] = 0;
	
	for(int i=1; i<h; i++){
		long long div1 = i*w;
		long long div2 = (h-i)*w;
		long long arr[3];
		if(w%2){
			arr[0] = i*(w/2+1);
			arr[1] = i*(w/2);
		}
		else{
			arr[0] = i*(w/2);
			arr[1] = i*(w/2);
		}
		arr[2] = div2;
		r[2] = min(r[2],*max_element(arr,arr+3)-*min_element(arr,arr+3));
		if(w%2){
			arr[0] = (h-i)*(w/2+1);
			arr[1] = (h-i)*(w/2);
		}
		else{
			arr[0] = (h-i)*(w/2);
			arr[1] = arr[0];
		}
		arr[2] = div1;
		r[2] = min(r[2],*max_element(arr,arr+3)-*min_element(arr,arr+3));
	}
	for(int i=1; i<w; i++){
		long long div1 = i*h;
		long long div2 = (w-i)*h;
		long long arr[3];
		if(h%2){
			arr[0] = (h/2+1)*i;
			arr[1] = (h/2)*i;
		}
		else{
			arr[0] = (h/2)*i;
			arr[1] = arr[0];
		}
		arr[2] = div2;
		r[3] = min(r[3],*max_element(arr,arr+3)-*min_element(arr,arr+3));
		
		if(h%2){
			arr[0] = (h/2+1)*(w-i);
			arr[1] = (h/2)*(w-i);
		}
		else{
			arr[0] = (h/2)*(w-i);
			arr[1] = arr[0];
		}
		arr[2] = div1;
		r[3] = min(r[3],*max_element(arr,arr+3)-*min_element(arr,arr+3));
	}
	cout<<*min_element(r,r+4);
}