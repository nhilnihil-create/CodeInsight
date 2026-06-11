#include <iostream>      
//#include <string>      
#include <algorithm>      
//#include <bits/stdc++.h>      
using namespace std;      
      
int main() {      
    ios::sync_with_stdio(0);      
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    int arr[26]={};
    for (int i=0; i<s.length(); i++){
    	arr[int(s[i]-'a')]++;
    }
    for (int i=0; i<26;i++){
    	if (arr[i]==0){
    		cout << char(i+'a')<< endl;
    		return 0;
    	}
    }
    cout << "None"<< endl;
}