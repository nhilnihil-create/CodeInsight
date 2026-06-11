#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> a(n), b(0);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int num=0;
    if(n%2==0) num++;

    for(int i=0; i<n; i++){
        if(i%2==num){
           b.push_front(a[i]); 
        }
        else b.push_back(a[i]);
    }

    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;

}