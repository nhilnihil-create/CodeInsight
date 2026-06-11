#include<iostream>
#include<math.h>
using namespace std;

#define ll long long
int main(){

string s;
cin>>s;

int arr[26]{0};
for (char c:s){
    arr[c-'a']++;
}
for(int i=0;i<26;i++){
    if(arr[i]%2!=0)
    {
        cout<<"No";
        return 0;
    }
}
cout<<"Yes";

}
