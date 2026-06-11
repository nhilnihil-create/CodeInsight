#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base:: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
    int n,l;
    cin>>n>>l;

    string bal[n];
    for(int i=0;i<n;i++){
        cin>>bal[i];
    }
 string mn=bal[0];
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(bal[j]<bal[i]){
            mn=bal[j];
            bal[j]=bal[i];
            bal[i]=mn;
        }
      }
    }
    for(int i=0;i<n;i++){
        cout<<bal[i];
    }

 return 0;
}
