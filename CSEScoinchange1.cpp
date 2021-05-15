#include<bits/stdc++.h>
#define int int64_t
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
int solve(vector<int> &v, int x){

    if(x == 0) return 1;
    if(x < 0) return 0;

    if(dp[x] != -1) return dp[x];

    int ans = 0;

    for(int coin : v){

        if(coin <= x){
            ans = (ans + solve(v, x-coin))%mod;
        }

    }

    return dp[x] = ans;

}


int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, x; cin>>n>>x;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    memset(dp, -1, sizeof dp);
    cout<<solve(v, x);

    return 0;
}