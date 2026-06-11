#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
    vector<long long> a(100000),b(100000),c(100000);
    cin >> a.at(0) >> b.at(0)>> c.at(0);

    if(a.at(0) % 2 ==1 || b.at(0)%2==1 || c.at(0)%2==1){
        cout << "0" << endl;
        return 0;
    }else if(a == b && b == c){
        cout << "-1" << endl;
        return 0;
    }

    int count = 1;
    for(int i=1;;i++){
        a.at(i) = b.at(i-1)/2 + c.at(i-1)/2;
        b.at(i) = a.at(i-1)/2 + c.at(i-1)/2;
        c.at(i) = a.at(i-1)/2 + b.at(i-1)/2;
        if(a.at(i) % 2 ==1 || b.at(i)%2==1 || c.at(i)%2==1){
            cout << count << endl;
            return 0;
        }

        count++;

    }
 }

    
