#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long N,sum_p=0,sum_n=0,count_p=0,count_n=0;
    cin>>N;
    int A[N];
    for(int i=0;i<N;++i)cin>>A[i];

        for(int i=0;i<N;++i){
            sum_n+=A[i];

            if(i%2==0){
                if(sum_n<=0){
                    count_n+=1-sum_n;
                    sum_n=1;
                }
            }else{
                if(sum_n>=0){
                    count_n+=sum_n+1;
                    sum_n=-1;
                }
            }
        }



        for(int i=0;i<N;++i){
            sum_p+=A[i];

            if(i%2==1){
                if(sum_p<=0){
                    count_p+=1-sum_p;
                    sum_p=1;
                }
            }else{
                if(sum_p>=0){
                    count_p+=sum_p+1;
                    sum_p=-1;
                }
            }
        }
    long long ans=min(count_p,count_n);
        
cout<<ans;



}