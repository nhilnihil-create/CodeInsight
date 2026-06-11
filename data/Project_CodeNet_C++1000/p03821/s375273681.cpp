#include <bits/stdc++.h>
using namespace std;
 

 
int main() {


    int n;
    cin>>n;

    vector<int> A(n),B(n);
    for(int i=0;i<n;i++){
        cin>>A.at(i)>>B.at(i);
    }

    int64_t sum=0;
    for(int i=n-1;i>=0;i--){
        if( ((A.at(i)+sum)%B.at(i)) != 0 )
            sum+=B.at(i)-(A.at(i)+sum)%B.at(i);
    }

    cout<<sum<<endl;

 	return 0;
}
