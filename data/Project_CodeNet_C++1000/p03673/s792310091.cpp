#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    deque<int> d;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        if(i%2==1){
            d.push_back(a);
        }
        else d.push_front(a);
    }
    if(n%2==1){
        for(int i=0; i<n; i++){
            int a = d.back();
            cout << a << " ";
            d.pop_back();
        }
        cout << endl;
    }
    else{
        for(int i=0; i<n; i++){
            int a = d.front();
            cout << a << " ";
            d.pop_front();
        }
        cout << endl;
    }
}