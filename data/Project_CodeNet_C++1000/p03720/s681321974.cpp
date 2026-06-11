#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int city[n];
    int i,j;
    int a[m],b[m];
    for(i=0;i<n;i++)
        city[i] =0;
    
    for(i=0;i<m;i++)
        cin >> a[i] >> b[i];
    
    for(i=0;i<m;i++){
        city[a[i]-1] +=1;
        city[b[i]-1] +=1;
    }
    
    for(i=0;i<n;i++)
        cout << city[i] << endl;
}