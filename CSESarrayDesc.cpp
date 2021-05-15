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

const int mod = 1e9 + 7;
 
int solve(int n, vector<int>& arr, int m){
    
    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    
    if(arr[0] != 0){
        for(int x=1; x<=m; x++){
            if(arr[0] == x){
                dp[1][x] = 1;
            }else dp[1][x] = 0;
        }
    }else{
        for(int x=1; x<=m; x++){
            dp[1][x] = 1;
        }
    }   
    
    for(int i=2; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(arr[i-1] == 0 || arr[i-1] == j){
                dp[i][j] = ((j-1 >= 1 ? dp[i-1][j-1] : 0 )+ dp[i-1][j] + (j+1 <= m ? dp[i-1][j+1] : 0))%mod;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    
    int sum = 0;
    for(int i=0; i<m+1; i++){
        sum = (sum + dp[n][i])%mod;
    }
    
    return sum;

}



int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    cout << solve(n, v, m);

    return 0;
}