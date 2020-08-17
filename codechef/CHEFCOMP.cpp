#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int p[200002];
long long int a[200002];
long long int b[200002];

long long int d[200002];

long long int n;
long long int nodes_processed = 0;
bool n_processed[200002];

long long int pop_dfs(long long int city,unordered_map<long long int,int> g[]){

  long long int visited[200002] = {0};  
  long long int ans = 0;       
    
  stack<long long int> q;
  q.push(city);

  while(!q.empty()){
     long long int source = q.top();
     q.pop();
     
  //   cout<<" city="<<city<<endl;
  //   cout<<" source="<<source<<endl;
     
    if(visited[source]){
        continue;
    }else{
        visited[source]=1;
        ans =ans + a[source];
    }

    for(auto child : g[source]){
        if(child.second && !visited[child.first]){
             q.push(child.first);
        }
    }
  }

  return ans;  

}

bool validate_dfs(long long int city,unordered_map<long long int,int> g[],long long int pop,long long int day,long long int pop_to_reduce){

  long long int visited[200002] = {0};  
    
  stack<long long int> q;
  q.push(city);

  while(!q.empty()){
     long long int source = q.top();
     q.pop();
     
  //   cout<<" city="<<city<<endl;
  //   cout<<" source="<<source<<endl;
     
    if(visited[source]){
        continue;
    }else{
        visited[source]=1;
        // cout<<"child for city "<<city<<endl;
        b[source] = b[source] - min(pop_to_reduce,b[source]);
        // cout<<"child reducded pop to "<<b[city]<<endl;
        if(b[source]<=0 && d[source]==-1){
             d[source] = day;
             nodes_processed++;
             n_processed[source] = true;
        }
        else if(b[source]>pop && n_processed[source] == false){
              nodes_processed++;
              n_processed[source] = true;
        }
        
        

    }

    for(auto child : g[source]){
        if(child.second && !visited[child.first]){
             q.push(child.first);
        }
    }
  }

  if(nodes_processed>=n){
        return false;
    }else{
        return true;
    }

}


int main() {
    long long int t;
    cin>>t;
    
    while(t--){
       
       cin>>n;
       
       unordered_map<long long int,int> g[n+1];

       
        for(long long int i=0;i<=n;i++){
           d[i]=-1;
           n_processed[i]=false;
        }
       
       for(long long int i=1;i<=n-1;i++){
           long long int u,v;
           cin>>u>>v;
        //   g[u].push_back(v);
        //   g[v].push_back(u);
            g[u][v]=1;
            g[v][u]=1;
       }
       
       for(long long int i=1;i<=n;i++){
           cin>>p[i];
       }
       
        for(long long int i=1;i<=n;i++){
           cin>>a[i];
       }
       
        for(long long int i=1;i<=n;i++){
           cin>>b[i];
       }

       bool flag = true;
       nodes_processed = 0;
       
       for(long long int i=1;i<=n ;i++){
        
        
        long long int city = p[i];
        
        // cout<<" for city "<<city<<endl;
        b[city] = b[city] - min(a[city],b[city]);
        // cout<<" reducded pop to "<<b[city]<<endl;
        if(b[city]<=0 && d[city]==-1){
             d[city] = i;
             nodes_processed++;
        }
        
        n_processed[city] = true;

        // if(nodes_processed>=n){
        //         flag = false;
        //         break;
        // }
        
        

        for(auto child : g[city]){

          long long int child_city = child.first;
          
          if(g[city][child_city]==0 || g[child_city][city]==0){
              continue;
          }
          
            g[city][child_city]=0;
            g[child_city][city]=0;

        //   long long pop = pop_dfs(child_city,g);
          flag = validate_dfs(child_city,g,0,i,a[city]);
          
        //   if(!flag){
        //       break;
        //   }

        } 
        // if(!flag){
        //       break;
        //   }
            
       }
       
    //   cout<<"-------";
       for(long long int i=1;i<=n;i++){
           cout<<d[i]<<" ";
       }
      
       cout<<endl;
    }
  return 0;
}