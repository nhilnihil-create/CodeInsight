#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    int h,w,n,c=1,d=1;
    cin>>h>>w>>n;
    vector<int>a(10000000);
    vector<vector<int>> b(1000,vector<int>(1000));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++ ){
            if(i%2==0){
                b[i][j]=c;
            }
            else{
                b[i][w-j-1]=c;
            }
            d++;
            if(d>a[c-1]){
                c++;
                d=1;
            }
            else{
            	
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++ ){
           cout<<b[i][j]<<flush;
           if(j!=w-1){
               cout<<" "<<flush;
           }
        }
        cout<<endl;
    }


    return 0;
}