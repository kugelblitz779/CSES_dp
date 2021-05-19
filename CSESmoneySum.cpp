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
 
set<int> st;
void solve(vector<int> &arr, int n){
    
    if(n == 0) return;
    
    int ele = arr[n-1];
    
    vector<int> v;
    for(int x : st){
        v.emplace_back(x + ele);
    }
    st.insert(ele);
    for(int x : v) st.insert(x);
    
    solve(arr, n-1);
}



int32_t main(){

	// freopen("input.txt", "r", stdin);

	// freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
   
    solve(v, n);
    
    cout << st.size() <<"\n";
    for(int x : st) cout << x <<" ";

    
    return 0;
}