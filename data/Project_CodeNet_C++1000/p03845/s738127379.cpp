#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,M,p,x;
    cin >> N;
    int data_T[N];
    
    for(int i=0;i<N;i++) cin >> data_T[i];
    
    cin >> M;
    
    for(int i=0;i<M;i++){
        cin >> p >> x;
        int sum = 0;
        for(int i=0;i<N;i++){
            if(i == (p-1)) sum += x;
            else sum += data_T[i];
        }
        cout << sum << endl; 
    }
    
}