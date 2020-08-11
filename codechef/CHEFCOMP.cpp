#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int t;
    cin>>t;
    
    while(t--){
       long long int n;
       cin>>n;
       
       vector<long long int> g[n+1];
       long long int p[n+1];
       long long int a[n+1];
       long long int b[n+1];
       
       long long int d[n+1];
       
        for(long long int i=1;i<=n;i++){
           d[i]=-1;
        }
       
       for(long long int i=1;i<=n-1;i++){
           long long int u,v;
           cin>>u>>v;
           g[u].push_back(v);
           g[v].push_back(u);
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
       
       for(long long int i=1;i<=n;i++){
           int visited[n+1] = {0};
           long long int city = p[i];
    
           queue<long long int> q;
           q.push(city);

        //   b[city] = b[city] - min(a[city],b[city]);

        //   if(b[city]==0 && d[city]==-1 ){
        //         d[city] = i;
        //     }
           
           while(!q.empty()){
               long long int source = q.front();
               q.pop();
               
            //   cout<<" city="<<city<<endl;
            //   cout<<" source="<<source<<endl;
               
              if(visited[source]){
                  continue;
              }else{
                  visited[source]=1;
                  
                   b[source] = b[source] - min(a[city],b[source]);
                    if(b[source]==0 && d[source]==-1 ){
                         d[source] = i;
                    }
              }
               
               for(long long int child : g[source]){
                  if(!visited[child]){
                       q.push(child);

                        // b[child] = b[child] - min(a[city],b[child]);
                        // if(b[child]==0 && d[child]==-1 ){
                        //      d[child] = i;
                        // }
                  }
               }
           }
           
            for(long long int child : g[city]){

                g[city].erase(std::remove(g[city].begin(), g[city].end(), child), g[city].end()); 
                g[child].erase(std::remove(g[child].begin(), g[child].end(), city), g[child].end()); 

            }
        //   cout<<" fruits left after visiting node"<<city<<endl;
        //   for(int i=1;i<=n;i++){
        //         cout<<b[i]<<" ";
        //     }
        //     cout<<endl;
       }
       
    //   cout<<"-------";
       for(int i=1;i<=n;i++){
           cout<<d[i]<<" ";
       }
      
       cout<<endl;
    }
  return 0;
}