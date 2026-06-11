#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    int x,odd=0;
    for(i=0;i<n;i++){
        cin>>x;
        if(x%2==1)odd++;
    }
    cout<<((odd%2==0)?"YES":"NO")<<endl;
}