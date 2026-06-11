#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int64_t> b(n);
    
    for(int i = 0; i<n; i++){
        cin >> a.at(i);
    }
    
    int64_t ans_1 = 0;
    int64_t ans_2 = 0;
    
    b.at(0)=a.at(0);
    if (b.at(0) <= 0){
        ans_1 += 1-b.at(0);
        b.at(0)=1;
    }
        
    for(int i=1; i<n; i++){
        b.at(i) = b.at(i-1) + a.at(i);
        if ((i%2)==1){
            if (b.at(i)>=0){
                ans_1 += 1+b.at(i);
                b.at(i)= -1;
            }
        }
        else{
            if (b.at(i)<=0){
                ans_1 += 1-b.at(i);
                b.at(i)=1;
            }
        }
    }
    
    b.at(0)=a.at(0);
    if (b.at(0) >= 0){
        ans_2 += 1+b.at(0);
        b.at(0)=-1;
    }
        
    for(int i=1; i<n; i++){
        b.at(i) = b.at(i-1) + a.at(i);
        if ((i%2)==1){
            if (b.at(i)<=0){
                ans_2 += 1-b.at(i);
                b.at(i)= 1;
            }
        }
        else{
            if (b.at(i)>=0){
                ans_2 += 1+b.at(i);
                b.at(i)=-1;
            }
        }
    }
    cout << min(ans_1, ans_2) << endl;
}
