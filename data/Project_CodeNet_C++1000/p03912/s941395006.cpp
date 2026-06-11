#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
int N,M;
vector<int> v;
int same[100001];//1ペアで1
int p[100001];
int main(){
        REP(i,100001){
            same[i]=0;
            p[i]=0;
        }
	cin>>N>>M;
	//Mが1の対策
	if(M==1){
	   cout<<N/2<<endl;
	   return 0;
	}
	REP(i,N){
	    int a;
	    cin>>a;
            v.push_back(a);
	}
        sort(v.begin(),v.end());
        int temp=v[0];
        p[temp%M]++;
        for(int i=1;i<N;i++){
            if(v[i]==temp){
               same[temp%M]++;
               p[temp%M]++;
               if(i!=N-1){
                  temp=v[i+1];
                  p[temp%M]++;
               }
               i++;
               continue;
            }
            temp=v[i];
            p[temp%M]++;
        }
      /*  REP(i,M){
            cout<<"p["<<i<<"]="<<p[i]<<" "<<same[i]<<endl;
        }*/
        long long ans=0;
        REP(i,M/2+1){
            if(i==0){
                ans+=p[i]/2;
                continue;
            }
            if((M%2==0)&&(i==M/2)){
                ans+=p[i]/2;
               // cout<<p[i]/2<<endl;
                break;
            }
            int a=min(p[i],p[M-i]);
            //cout<<p[i]<<"a"<<p[M-i]<<endl;
            p[i]-=a;
            p[M-i]-=a;
            ans+=a;
            int b=min(p[i]/2,same[i]);
            int c=min(p[M-i]/2,same[M-i]);
            ans+=b;
            ans+=c;
            //cout<<a<<" "<<b<<" "<<c<<endl;
        }
        cout<<ans<<endl;
	return(0);
}