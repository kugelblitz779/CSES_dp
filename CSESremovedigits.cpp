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

int dp[1000005];
int solve(int n){
    
    if(n <= 0) return 0;
    
    if(n > 0 && n <= 9){
        return 1;
    }
    
    if(dp[n] != -1) return dp[n];
    
    int ans = INT_MAX;
    int tmp = n;
    while(n > 0){
        
        int r = n%10;
        if(r > 0){
            ans = min(ans, 1 + solve(tmp-r));
        }
        n = n/10;   
    }
    
    return dp[tmp] = ans;
}



int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    memset(dp, -1, sizeof dp);
    cout<<solve(n);

    return 0;
}