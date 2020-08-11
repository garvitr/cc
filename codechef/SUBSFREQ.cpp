#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;
long long int power[500001] = {0};


long long int cal(long long int n){
    if(power[n]!=0){
        return power[n];
    }
    
    if(n==1){
        return 2;
    }
    
    else power[n] = (2*(cal(n-1)%MOD))%MOD;
    return power[n];
}


int main() {
    long long int t;
    cin>>t;
    
    power[0] = 1;
    power[1] = 2;
    
    while(t--){
       long long int n;
       cin>>n;
       std::vector<long long int> v;
       for(int i=0;i<n;i++){
           long long int temp;
           cin>>temp;
           v.push_back(temp);
       }
       
       for(int i=1;i<=n;i++){
           cout<<cal(n-i)<<" ";
       }
       cout<<endl;
    }
	return 0;
}