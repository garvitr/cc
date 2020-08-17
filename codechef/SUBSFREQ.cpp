#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;
long long int power[5000001] = {0};
long long row[5000001];
long long int ncr_ans[10000][10000] = {0};


long long int cal(long long int n){
    if(power[n]!=0){
        return power[n];
    }
    
    if(n==1){
        return 2;
    }
    
    else power[n] = (2*(cal(n-1)))%MOD;
    return power[n];
}



int ncr(long long int n,long long int r)
{
    if(n<0 || r<=0){
        return 0;
    }

    if(r>n){
      return 1;
    }

    if(n==r) return 1;
    if(r==1) return n;

    
    if(n>1000 || r>1000){
        return ncr(n-1,r) + ncr(n-1,r-1);
    }

    if(ncr_ans[n][r]!=0){
        return ncr_ans[n][r];
    }

     ncr_ans[n][r] = ncr(n-1,r) + ncr(n-1,r-1);
     
     if(n>r){
         ncr_ans[n][n-r] = ncr_ans[n][r];
     }else{
         ncr_ans[n][r-n] = ncr_ans[n][r];
     }
     return  ncr_ans[n][r];
}

int main() {
    long long int t;
    cin>>t;
    
    power[0] = 1;
    power[1] = 2;
    
    while(t--){
       long long int n;
       cin>>n;

       long long int count[n+1] = {0};
       long long int ans[n+1] = {0};
       map<long long int,long long int> dp[n+1];
       unordered_map<long long int,long long int> dp_ans[n+1];
       long long int max_val = 0;
       set<long long int> s;
       for(int i=1;i<=n;i++){
          long long int num;
           cin>>num;
           count[num]++;
           s.insert(num);
           dp_ans[num][0] = 1;
           // dp_ans[num][count[num]] = dp_ans[num][count[num]-1] + ncr(count[num],)

           // dp[count[num]][-num]++;   

           // if(count[num]>max_val){
           //  max_val = count[num];
           // }        
       }

       for(auto elem : s){

        for(long long int i=1;i<=count[elem];i++){
          dp_ans[elem][i] = dp_ans[elem][i-1] + ncr(count[elem],i);
        }

       }


       for(auto elem : s){

        for(long long int i=1;i<=count[elem];i++){
          long long int temp_ans = 1;

          for(auto sub_elem: s){

            if(sub_elem = elem){
              temp_ans = (temp_ans*(ncr(count[elem],i)%MOD))%MOD;
            }else if(sub_elem < elem){
              temp_ans  = (temp_ans*(ncr(count[sub_elem],min(i-1,count[sub_elem]))%MOD))%MOD;
            }else{
              temp_ans  = (temp_ans*(ncr(count[sub_elem],min(i,count[sub_elem]))%MOD))%MOD;
            }

          }
           ans[elem] = (ans[elem]%MOD + temp_ans%MOD)%MOD;


        }
       }

       
       
      for(int i=1;i<=n;i++){
          cout<<ans[i]%MOD<<" ";
      }
       
       cout<<endl;
    }
  return 0;
}