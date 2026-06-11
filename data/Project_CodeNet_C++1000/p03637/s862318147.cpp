#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> four;
    queue<int> two;
    queue<int> one;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a%4==0)four.push(a);
        else if(a%2==0)two.push(a);
        else one.push(a);
    }
    long long int x[n];
    for(int i=0;i<n;i++){
        if(i%2==0 && !one.empty()){
            x[i]=one.front();
            one.pop();
        }
        else if(i%2==0 && !two.empty()){
            x[i]=two.front();
            two.pop();
        }
        else if(i%2==0 && !four.empty()){
            x[i]=four.front();
            four.pop();
        }
        else if(i%2==1 && !four.empty()){
            x[i]=four.front();
            four.pop();
        }
        else if(i%2==1 && !two.empty()){
            x[i]=two.front();
            two.pop();
        }
        else if(i%2==1 && !two.empty()){
            x[i]=one.front();
            one.pop();
        }
    }
    for(int i=0;i<n-1;i++){
        if((x[i]*x[i+1])%4!=0){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}