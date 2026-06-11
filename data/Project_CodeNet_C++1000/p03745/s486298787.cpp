#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    long long L[N];
    for(int i = 0; i < N;i++)cin >>L[i];
    long long ans = 0;
    long long cont = 0;
    while(true){
        
        if(L[cont]<L[cont+1]){
            //cout <<"a"<<endl;
            while(L[cont]<=L[cont+1]&&cont<N)cont++;
        }else if(L[cont]>L[cont+1]){
            //cout <<"b"<<endl;
            while(L[cont]>=L[cont+1]&&cont<N)cont++;
        }else{
            cont++;
            continue;
        }
        cont++;
        //cout << cont <<endl;
        ans++;
        if(cont>=N)break;
    }
    cout <<ans <<endl;
    
}

    
    

