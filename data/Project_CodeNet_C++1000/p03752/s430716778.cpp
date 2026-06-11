#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int next_combitantion(int sub){
    int x=sub & -sub,y= sub+x;
    return (((sub&~y)/x)>>1)|y;
    
    
}

bool bitget(int a,int b){
  return a&1<<b;
}


int main(){
    int N,K;
    cin >> N >> K;
    vector<long long> A(N);
    for(long long &i:A)cin >> i;
    
    long long minc=numeric_limits<long long>::max();
    
    for(int i=(1<<K)-1;i<(1<<N);i=next_combitantion(i)){
        long long dis=0;
        long long pre=0;
        for(int j=0;j<N;j++){
            if(bitget(i, j)){
                if(A[j]<=pre){
                    dis+=pre-A[j]+1;
                    pre++;
                }else{
                    pre=max(pre,A[j]);
                }
            }else{
                
                pre=max(pre,A[j]);
               
            }
            
            
        }
        
        minc=min(minc,dis);
        
    }
    
    cout << minc << endl;
    
}