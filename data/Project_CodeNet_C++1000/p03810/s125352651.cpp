 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
LL A[100001];
LL gcd(LL a,LL b){
   if(b==0)return a;
   return gcd(b,a%b);
}
int main(){
    cin>>N;
    REP(i,N){
        cin>>A[i];
    }
    int ans=0;
    while(1){
        int even=0;
        REP(i,N){
            if(A[i]%2==0)even++;
        }
        if(even%2==1)break;
        if(even!=N-1){
           ans=1-ans;
           break;
        }
        bool check=false;
        REP(i,N){
            if(A[i]==1){
               check=true;
            }
            A[i]=A[i]/2;
        }
        ans=1-ans;
        if(check){
           break;
        }
        
        LL ggg=A[0];
        REP(i,N-1){
            ggg=gcd(A[i],ggg);
        }
        REP(i,N){
            A[i]=A[i]/ggg;
        }
    }
    
    if(ans==0){
       cout<<"First"<<endl;
    }else{
       cout<<"Second"<<endl;
    }
}