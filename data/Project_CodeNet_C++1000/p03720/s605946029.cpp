#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int city[n];
    int i,j;
    int a,b;
    for(i=0;i<n;i++)
        city[i] =0;
    
    for(i=0;i<m;i++){
        cin >> a >> b;
            for(j=0;j<n;j++){
                if(a==j+1 || b==j+1)
                    city[j]++;
            }
    }
    
    for(i=0;i<n;i++)
        cout << city[i] << endl;
}