#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC60(void);
void ABC61(void);
void ABC62(void);
void ABC63(void);
void ABC64(void);
void ABC65(void);
void ABC66(void);
void ABC67(void);
void ABC68(void);
void ABC69(void);

int main(void){
    ABC67();
}

void ABC67(){
    int n,k,i,sum=0;
    cin>>n>>k;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for(i=0;i<k;i++){
        sum+=vec[i];
    }
    cout<<sum<<endl;
}