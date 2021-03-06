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
        long long int ans[w+1][n+1] = {0};
        int chosen[w+1][n+1] = {0};

        for(int weight=1;weight<=w;weight++){
            for(int index=1;index<=n;index++){
                if(wt[index]<=weight){
                    long long int ans_incl_val = ans[weight-wt[index]][index-1] + val[index];
                    long long int ans_excl_val = ans[weight][index-1];
                    chosen[weight][index] = ans_incl_val>ans_excl_val ? 1 : 0;
                    ans[weight][index] = max(ans_incl_val,ans_excl_val);
                }else{
                    ans[weight][index] = ans[weight][index-1];
                }
                // cout<<"i="<<i<<" j="<<j<<" ans="<<ans[i][j]<<endl;
            }
        }
        cout<<ans[w][n]<<endl;

        /*
        chosen numbers
        */
        long long int weight = w;
        int index = n;
        long long int answer = 0;
        while(weight>0 && index>0){
            if(chosen[weight][index]){
                weight  = weight - wt[index];
                answer = answer + val[index];
                cout<<"chosen index = "<<index<<endl;
            }
            index --;
        }
        cout<<answer<<endl;

    }

	//code
	return 0;
}