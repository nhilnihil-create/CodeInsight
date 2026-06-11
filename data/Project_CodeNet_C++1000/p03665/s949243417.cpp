    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	long long n,p,one=0,zero=0,a,ans;
    	cin>>n>>p;
    	for(int i=0;i<n;i++){
    		cin>>a;
    		if(a%2==0){
    			zero++;
    		}
    		else{
    			one++;
    		}
    	}
    	if(p==1 && one==0){
    		cout<<"0"<<endl;
    	}
		else if(p==0 && one==0){
			ans=pow(2,n);
			cout<<ans<<endl;
		}
    	else{
    		zero=pow(2,zero);
    		one=pow(2,one-1);
    		ans=zero*one;
    	cout<<ans<<endl;
    	}
      return(0);
    }