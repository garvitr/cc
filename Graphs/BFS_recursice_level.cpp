#include <bits/stdc++.h>

using namespace std;

int main(){
	long n;
	cin>>n;

	vector<long> g[n+1];
	int visited[n+1] = {0};
	int level[n+1] = {0};

	for(int i=0;i<n;i++){
		long a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	long target_level;
	cin>>target_level;

	queue<long> q;
	q.push(1);
	level[1]=1;

	while(!q.empty()){
		long node = q.front();
		q.pop();

		if(visited[node]){
			continue;
		}else{
			visited[node]=1;
		}

		for(long child : g[node]){
			if(!visited[child]){
				level[child]=level[node]+1;
				q.push(child);
			}
		}
	}

	long ans = 0;
	for(int i=1;i<=n;i++){
		if(level[i]==target_level){
			ans++;
		}
	}
	cout<<ans<<endl;


	return 0;
}