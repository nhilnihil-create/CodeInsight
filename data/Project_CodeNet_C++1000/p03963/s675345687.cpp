#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,k;
        cin>>n>>k;
  		int z=k;
        for(int i=0;i<n-1;i++)  {
                z*=k-1;
        }
        cout<<z<<endl;
}
                                              