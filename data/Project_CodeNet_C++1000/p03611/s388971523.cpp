#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    vector<long long>vec1(1000000,0);
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
        if(vec.at(i)==0){
            vec1.at(vec.at(i))++;
            vec1.at(vec.at(i)+1)++; 
        }
        else{
        vec1.at(vec.at(i))++;
        vec1.at(vec.at(i)-1)++;
        vec1.at(vec.at(i)+1)++;  
        }  
    }
    sort(vec1.begin(),vec1.end());
    reverse(vec1.begin(),vec1.end());
    cout<<vec1.at(0)<<endl;
}