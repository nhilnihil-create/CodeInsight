#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,n,count=1;
    cin >> n;
    vector<int> a(n);
    bool big=true,small=true;
    for(i=0;i<n;i++){
        cin >> a.at(i);
        if(i==0)continue;
        else{
            if(a.at(i-1)==a.at(i))continue;
            else if(a.at(i-1)<a.at(i)){
                if(big){
                    big=true;
                    small=false;
                }
                else{
                    big=true;
                    small=true;
                    count++;
                }
            }
            else if(a.at(i-1)>a.at(i)){
                if(small){
                    big=false;
                    small=true;
                }
                else{
                    big=true;
                    small=true;
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}