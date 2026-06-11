#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int llo;
#define a first
#define  b second
#define endl "\n"
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	llo it[n];
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}

	vector<pair<llo,llo>> ran;
	llo su=0;
	for(llo i=0;i<n-1;i++){
		if(it[i]<=it[i+1]){
			su+=it[i+1]-it[i];
			ran.pb({it[i],-i});		

			ran.pb({it[i+1],i+1});
		}		
		else{
			su+=it[i+1]+m-it[i];
			ran.pb({it[i],-i});		
			ran.pb({it[i+1]+m,i+1});
		}
	}
	sort(ran.begin(),ran.end());
	llo ind=0;

	llo ans[2*m];
	llo co=0;
	for(llo i=0;i<2*m;i++){
		ans[i]=su;
	}
	llo su2=0;
	llo mi=su;
	for(llo i=1;i<2*m+1;i++){
		llo su3=0;
		llo co3=0;
		while(ind<ran.size()){
			if(ran[ind].a==i){
				if(ran[ind].b<=0){
					co3+=1;
					su3+=i;
				}
				else{
					co-=1;
					su2-=it[ran[ind].b-1];
				}
				ind+=1;
			}
			else{
				break;
			}
		}
		ans[(i-1)%m]-=i*co-su2;

		mi=min(mi,ans[(i-1)%m]);
		su2+=su3;
		co+=co3;
	}
	cout<<mi<<endl;


















	return 0;
}