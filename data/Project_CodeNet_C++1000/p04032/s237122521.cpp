#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair<int ,int >
#define S second
#define F first
#define PI 3.1415926535897932384626
#define SPEED std::ios_base::sync_with_stdio(false);

int main(){
    SPEED
    string s;
    cin>>s;
    int n = s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout<<i+1<<" "<<i+2;
            return 0;
        }
        if(i<n-2){
            if(s[i]==s[i+2]){
                cout<<i+1<<" "<<i+3;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1;

}
