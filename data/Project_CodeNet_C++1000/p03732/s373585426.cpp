#include <bits/stdc++.h>
using namespace std;

int main(){

  int N,W;cin>>N>>W;
    vector<long long int> S1,S2,S3,S4;
    long long int j;
    for(int i=0;i<N;i++){
        long long int a;
        int b;cin>>a>>b;
        if(i==0){
            S1.push_back(b);
            j=a;
        }
        else{
            if(a==j) S1.push_back(b);
            if(a==j+1) S2.push_back(b);
            if(a==j+2) S3.push_back(b);
            if(a==j+3) S4.push_back(b);
        }
    }
    sort(S1.rbegin(),S1.rend());
    sort(S2.rbegin(),S2.rend());
    sort(S3.rbegin(),S3.rend());
    sort(S4.rbegin(),S4.rend());
    vector<long long int> T1(S1.size()+1,0),T2(S2.size()+1,0),T3(S3.size()+1,0),T4(S4.size()+1,0);
    for(int i=0;i<S1.size();i++){
        T1[i+1]=T1[i]+S1[i];
    }
    for(int i=0;i<S2.size();i++){
       T2[i+1]=T2[i]+S2[i];
    }
    for(int i=0;i<S3.size();i++){
        T3[i+1]=T3[i]+S3[i];
    }
    for(int i=0;i<S4.size();i++){
        T4[i+1]=T4[i]+S4[i];
    }
    long long int ans=0;
    for(int i=0;i<T1.size();i++){
        for(int f=0;f<T2.size();f++){
            for(int k=0;k<T3.size();k++){
                for(int l=0;l<T4.size();l++){
                    if(j*(i)+(j+1)*(f)+(j+2)*(k)+(j+3)*(l)<=W){
                    long long int sum=T1[i]+T2[f]+T3[k]+T4[l];
                        ans=max(ans,sum);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

