#include<bits/stdc++.h>
#define ll int64_t
#define pb emplace_back
#define mp make_pair
#define acc accumulate
#define f(n) for(int i=0;i<n;i++) 
#define f1(n) for(int i=1;i<n;i++) 
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
typedef vector<int> vi;

const int mod = 1000000007;


int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, sum; cin>>n>>sum;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(sum+1));

    for(int i=0; i<sum+1; i++){
        dp[0][i] = 0;
    }

    for(int i=0; i<n+1; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(v[i-1] <= j){
                dp[i][j] = (dp[i][j-v[i-1]] + dp[i-1][j])%mod;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][sum];

    return 0;
}