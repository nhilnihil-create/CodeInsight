#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int h,w;
    cin>>h>>w;
    string a;
    
    map<char,int> book;
    
    rep(i,h){
        cin>>a;
        rep(j,w)book[a[j]]++;
    }
    
    vector<int> count(4,0);
    
    for(auto p: book){
        count[p.second%4]++;
    }
    
    if(h%2==1 && w%2==1){
        if(count[1]+count[3]!=1){
            cout << "No" << endl;
            return 0;
        }
        
        if(count[1]==1){
            count[0]++;
        }
        if(count[3]==1){
            count[2]++;
        }
        
        if(count[2] > (h/2)+(w/2) || (count[2]+(h/2)+(w/2))%2==1){
            cout << "No" << endl;
            return 0;
        }
        
        cout << "Yes" << endl;
        
    }else if(h%2==0 && w%2==0){
        if(count[1]!=0 || count[2]!=0 || count[3]!=0){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        
    }else{
        if(h%2)swap(h,w);
        
        if(count[1]!=0 || count[3]!=0){
            cout << "No" << endl;
            return 0;
        }
        
        if(count[2] > (h/2) || (count[2]+(h/2))%2==1){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        
    }
    
    return 0;
}