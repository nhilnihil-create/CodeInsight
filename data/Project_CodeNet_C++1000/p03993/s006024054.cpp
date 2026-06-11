#include<bits/stdc++.h>
#include<climits>
using namespace std;


int main(void){
    // Your code here!
    int N;
    cin >> N;
    int b;
    int a[N];
    bool f[N];
    
    
    
    
    for(int i = 0; i < N ;i++){
        cin >> b;
        a[i] = b-1;
        f[i] = true; 
    }
    
    int cont = 0;
    for(int i = 0; i < N;i++){
        if(f[i]&& a[a[i]] == i){
            cont++;
            f[a[i]] = false; 
        }
    }
    
    cout << cont << endl;
    

}
