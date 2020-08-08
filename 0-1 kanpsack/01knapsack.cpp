#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int wt[n+1] = {0};
        int val[n+1] = {0};

        for(int i=1;i<=n;i++){
            cin>>val[i];
        }

        for(int i=1;i<=n;i++){
            cin>>wt[i];
        }

        /*
        row(i) = weights (1->w)
        col(j) = value indexs (1->n)
        */
        int ans[w+1][n+1] = {0};

        for(int weight=1;weight<=w;weight++){
            for(int index=1;index<=n;index++){
                if(wt[index]<=weight){
                    int ans_incl_val = ans[weight-wt[index]][index-1] + val[index];
                    int ans_excl_val = ans[weight][index-1];
                    ans[weight][index] = max(ans_incl_val,ans_excl_val);
                }else{
                    ans[weight][index] = ans[weight][index-1];
                }
                // cout<<"i="<<i<<" j="<<j<<" ans="<<ans[i][j]<<endl;
            }
        }
        cout<<ans[w][n]<<endl;

    }

	//code
	return 0;
}