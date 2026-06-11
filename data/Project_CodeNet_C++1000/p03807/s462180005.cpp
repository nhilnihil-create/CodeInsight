#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    priority_queue<int> pq;
    int oddnum=0; 
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a%2==1){oddnum++;}
        pq.push(a%2);
    }

    if(oddnum%2==1){cout << "NO" << endl;}
    else{cout << "YES" << endl;}
    
    /*以下勘違いしたもの
    while(!pq.empty()){
        pq.pop();
        if(pq.empty()){cout << "No" << endl; return
        pq.pop();
        pq.push(0);
    }

    cout << "Yes" << endl;
    return 0;
    */
}