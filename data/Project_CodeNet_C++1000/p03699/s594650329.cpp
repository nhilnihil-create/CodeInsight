#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> s(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin >> s.at(i);
        sum+=s.at(i);
    }

    sort(s.begin(),s.end());
    if(sum%10==0){
        int i=0;
        while(1){
            if(s.at(i)%10==0) i++;
            else{
                sum-=s.at(i);
                break;
            }
            if(i==n){
                sum=0;
                break;
            }
        }
    }
    cout << sum << endl;
}