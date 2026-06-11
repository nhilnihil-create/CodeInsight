#include<iostream>
using namespace std;

int main(){
    long N;
    long p[100002]={};
    long count=0;

    cin >> N;
    for(long i=1;i<=N;i++){
        cin >> p[i];
    }

    for(long i=1;i<=N;i++){
        if(i==p[i]){
            if(i+1==p[i+1]){
                count++;
                i++;
            }
            else{
                count++;
            }
        }
    }

    cout << count << "\n";
    return 0;

}