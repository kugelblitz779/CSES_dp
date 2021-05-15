#include<bits/stdc++.h>
#define int int64_t
#define pb emplace_back
#define mp make_pair
#define acc accumulate
#define f(n) for(int i=0;i<n;i++) 
#define f1(n) for(int i=1;i<n;i++) 
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
using namespace std;
typedef vector<int> vi;


int dp[1000006];
int coins[101];

int solve(int x){

    int n = sizeof(coins)/sizeof(coins[0]);

    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i] , dp[ i - coins[j] ] + 1);
            } 
        }
    }

    if(dp[x] == INF) dp[x] = -1;
    return dp[x];
}

int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>coins[i];
    }
    int x; cin>>x;

    for(int i=1; i<=x; i++){
        dp[i] = INF;
    }

    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i] , dp[ i - coins[j] ] + 1);
            } 
        }
    }

    if(dp[x] == INF) dp[x] = -1;

    cout<<dp[x];

    return 0;
}