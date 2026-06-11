#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<long> a;
    for (int i=0; i<n; i++){
        long input;
        cin >> input;
        if (i & 1) a.push_front(input);
        else a.push_back(input);
    }
    for (int i=0; i<n; i++){
        if (n & 1){
            cout << a[n-1-i] << " ";
        }
        else{
            cout << a[i] << " ";
        }
    }
    return 0;
}