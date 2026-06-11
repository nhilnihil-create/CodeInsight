    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<iomanip>
    using namespace std;
     
     
    int main(){
    	string s;
    	cin>>s;
    	int N=s.size();
     
    	long long ans=0;
     
    	for(int bit=0;bit<(1<<(N-1));bit++){
    		long long sum=0;
     
    		for(int j=0;j<N-1;j++){
    			sum *=10;
    			sum +=s.at(j)-'0';
     
    			if(bit &(1<<j)){
    				ans+=sum;
    				sum=0;
    			}
    		}
     
    		sum *= 10;
    		sum += s.back()-'0';
    		ans += sum;
    	}
    	cout << ans <<endl;
     
    	return 0;
     
    }