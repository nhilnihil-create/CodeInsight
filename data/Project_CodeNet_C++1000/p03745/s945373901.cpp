#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }

    bool increase=true,reset=true;
    int count=1;
    for(int i=1; i<n; i++){
        if(reset){
            if(a.at(i)==a.at(i-1)) continue;
            else if(a.at(i)>a.at(i-1)){
                increase=true;
                reset=false;
            }
            else{
                increase=false;
                reset=false;
            }
        }
        else{
            if(increase){
                if(a.at(i)<a.at(i-1)){
                    count++;
                    reset=true;
                }
            }
            else{
                if(a.at(i)>a.at(i-1)){
                    count++;
                    reset=true;
                }
            }
        }
    }
    cout << count << endl;
}