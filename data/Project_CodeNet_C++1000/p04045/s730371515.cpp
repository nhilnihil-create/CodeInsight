#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(10),l;
    for(int i=0;i<k;i++){
        int d;
        cin>>d;
        v[d]++;
    }
    for(int i=n;;i++){
        int j=i;
        bool flag=true;
        while(j>0){
            int r=j%10;
            j/=10;
            if(v[r]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<i<<endl;
            return 0;
        }
    }
}