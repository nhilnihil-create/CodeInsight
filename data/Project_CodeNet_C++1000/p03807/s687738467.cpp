# include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A;
    int count=0;
    cin>>N;
 for (int i=0; i<N; i++){
        cin>>A;
        if(A%2==1){
            count++;
        }
    }
 if (count%2==0){
        cout<<"YES";
    }
 else{
        cout<<"NO";
    }
    return 0;
}