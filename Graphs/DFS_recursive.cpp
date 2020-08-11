#include <bits/stdc++.h>

using namespace std;

int main(){
	long n,m;
	cin>>n>>m;

	vector<long> g[n+1];

	for(int i=0;i<m;i++){
		long a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	long source;
	cin>>source;

	int visited[n+1] = {0};
	stack<long> st;
	st.push(source);


	while(!st.empty()){
		long node = st.top();
		st.pop();

		if(visited[node]){
			continue;
		}else{
			visited[node]=1;
		}

		for(long child : g[node]){
			if(!visited[child]){
				st.push(child);
			}
		}
	}

	long ans = 0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			ans++;
		}
	}
	cout<<ans<<endl;


	return 0;
}