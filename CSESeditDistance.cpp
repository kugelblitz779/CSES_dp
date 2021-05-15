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
 
int edit(string x, string y){

    int m = x.size(); int n = y.size();

    if(m == 0 && n == 0) return 0;
    if(m == 0 && n != 0) return n;
    if(m != 0 && n == 0) return m;

    int dp[m+1][n+1];

    for(int i=0; i<n+1; i++){
        dp[0][i] = i; 
    }
    for(int i=0; i<m+1; i++){
        dp[i][0] = i;
    }

    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){

            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }

        }
    }

    return dp[m][n];
}


int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string x, y; cin>>x>>y;

    cout << edit(x, y) <<"\n";

    
    return 0;
}