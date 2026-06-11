#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main() {
    string A;
    cin>>A;
    vector<char> arr;
    map<char, long> map;
    for(int i=0;i<A.size();++i){
        if(map[A[i]]==0)arr.push_back(A[i]);
        map[A[i]]++;
    }
    long ans = A.size()*(A.size()-1)/2;
    for(int i=0;i<arr.size();++i){
        ans -= map[arr[i]]*(map[arr[i]]-1)/2;
    }
    cout<<ans+1<<endl;
}
