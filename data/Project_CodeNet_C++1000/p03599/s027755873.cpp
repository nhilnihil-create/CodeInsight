#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	int a,b,c,d,e,f;
	long long w,s,max_s=0,max_sum=0;
	double s100_now=0,s100_max=0;
	cin >> a >> b >> c >> d >> e >> f;
	
	for(int i=0;i<=f/100;i++){
		for(int j=0;j<=f/100;j++){
			for(int x=0;x<=f/c;x++){
				for(int y=0;y<=f/d;y++){
					w=100*i*a+100*j*b;
					s=c*x+d*y;
					if(w+s>f)continue;
					if(w==0)continue;
					s100_now=((double)s*100)/(double)w;
					if(s100_now>e)continue;
					if(s100_max<=s100_now){
							s100_max=s100_now;
							max_sum=w+s;
							max_s=s;
					}
				}
			}
		}
	}
	
	cout << max_sum << " " << max_s << endl;	
					
	return 0;
}
