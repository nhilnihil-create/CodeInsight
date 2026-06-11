#include <bits/stdc++.h>
using namespace std;
int main(){
	int count=1;
	string S;
	cin>>S;
	vector<unordered_map<char,int>> mp((int)S.size());
	for(int i=0;i<(int)S.size();i++){
    	mp.at(i)[S.at(i)]=1;
    	if(i>0){
        	if(S.at(i-1)==S.at(i)){
            	count++;
            }
        }
    }
	if(count==(int)S.size()){
    	cout<<0<<endl;
    	return 0;
    }
	for(int i=1;i<(int)S.size();i++){
    	unordered_map<char,int> check;
    	for(int j=0;j<(int)S.size()-i;j++){
        	for(auto itr=mp.at(j+1).begin();itr!=mp.at(j+1).end();itr++){
            	mp.at(j)[itr->first]=1;
            }
        	for(auto itr=mp.at(j).begin();itr!=mp.at(j).end();itr++){
            	check[itr->first]++;
            }
        }
    	for(auto itr=check.begin();itr!=check.end();itr++){
        	if(itr->second==(int)S.size()-i){
            	cout<<i<<endl;
            	return 0;
            }
        }
    	check.clear();
    }
}