#include<iostream>
using namespace std;
int n, i, nr, c;
int v[100005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        c = max(v[i], c);
    }
    for(i = 1; i <= n; i++){
        if(c - v[i] > 1){
            cout<<"No";
            return 0;
        }
        if(c > v[i]){
            nr++;
        }
    }
    if(nr == 0 && c == n - 1){
        cout<<"Yes";
        return 0;
    }
    if(nr >= c || nr + (n - nr) / 2 < c){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}
