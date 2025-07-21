#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
 
#define endl           "\n"
#define F              first
#define S              second
#define pb             push_back
#define ub             upper_bound
#define lb             lower_bound
#define int            long long int
#define pii            pair <int, int>
#define vi             vector <int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define si             set <int>
#define spi            set <pii>
#define double         long double
#define lcm(x,y)       x*y/__gcd(x,y)
#define cy             cout<<"YES"<<endl;
#define cn             cout<<"NO"<<endl;
#define sz(x)          ((int) x.size())
#define all(v)         v.begin(), v.end()
#define srt(v)         sort(v.begin(),v.end());
#define rsrt(v)        sort(v.rbegin(),v.rend());
#define mnv(v)         *min_element(v.begin(),v.end())
#define mxv(v)         *max_element(v.begin(),v.end())
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define print1(a)      for(auto x : a) cout << x << " "; cout << endl;
#define print2(a)      for(auto x : a) cout << x.F << " " << x.S << endl;
#define vin(x,n)       vi x(n); for (int i = 0; i < n; ++i){cin>>x[i];}
#define srtbypairsc(v) sort(v.begin(), v.end(), []( pair<int, int>& l, pair<int, int>& r) { return l.second < r.second; } );
 
void __print(int x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define bug(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
#define bug(x...);
#endif
 
const int MOD = 1e9 + 7;
const int N = 200005;
 
vector<bool>isprime(N,true);
vi primes;
void genprimes(){ isprime[0]=isprime[1]=false;
    for (int i = 2; i*i < N; ++i) if(isprime[i]) {primes.pb(i);
    for (int j = i*i ; j < N; j += i) isprime[j] = false;}}
int SPF[1000001];
void genSPF(){ for(int i=0;i<=1000001;i++){ SPF[i]=i; }
    for (int i = 2; i*i <=1000001; ++i) if(SPF[i]==i){
    for (int j = i*i ; j <=1000001; j += i) if(SPF[j]==j){ SPF[j] = i;}}}
int MEX(vector<int> &a) {
    vector<bool> f(a.size() + 1, 0);for (int i : a) if(i <= (int) a.size()) f[i] = 1;
    int mex = 0; while (f[mex]) ++mex; return mex;}
int ceil_div(int a, int b) {return a / b + ((a ^ b) > 0 && a % b != 0);}
int add(int a,int b) {return ((a%MOD)+(b%MOD))%MOD;}
int multi(int a,int b) { return ((a%MOD)*(b%MOD))%MOD;}
int expo(int a,int b) { if (!b) return 1;int e = expo(a,b/2);if (b%2) return multi(a,multi(e,e)); else return multi(e,e);}
int INV(int a) { return expo(a,MOD-2);}
int divide(int a,int b) {return multi(a,INV(b));}
int fact[N];
void genfact() {fact[0] = 1;for(int i = 1; i < N; i++) fact[i] = (fact[i - 1]*i)%MOD; }
int NCR(int n ,int r)
{    if(n<r) return 0;
     return (((fact[n]*INV(fact[n-r]))%MOD)*INV(fact[r])%MOD)%MOD;}
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int n;
int arr[200000];
int dp[10000][1000];

//it's gives tle though try to use another form
int rec(int lev,int last_occ){

	if (lev==n )
	{
		return 0;
	}
	if (dp[lev][last_occ]!= -1)
	{
		return dp[lev][last_occ];
	}
	int ans=rec(lev+1,last_occ);

	if (arr[lev]>=last_occ)
	{
		ans=max(ans,1+rec(lev+1,arr[lev]));
	}

	return dp[lev][last_occ]=ans;
}

void printset(int level, int last_occ, vector<int>& cur, int max_len) {
    if (level == n) {
        if (cur.size() == max_len) {
            for (int x : cur) {
                cout << x << " ";
            }
            cout << endl;

        }
        return;
    }
    printset(level + 1, last_occ, cur, max_len);

    if (arr[level] >= last_occ) {
        cur.push_back(arr[level]);
        printset(level + 1, arr[level], cur, max_len);
        cur.pop_back(); 
    }
}
void solve() {
    

cin>>n;
for (int i = 0; i < n; ++i)
{
	cin>>arr[i];
}
memset(dp,-1,sizeof(dp));

vi cur;
int max_len=rec(0,0);

if (rec(0,0))
{
	cout<<max_len<<endl;
	printset(0,-1,cur,max_len);
}

/*
10
3 2 2 4 5 7 8 1 11 9
*/

}
//cout<<fixed<<setprecision(6);
 
int32_t main()
{
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
 
    clock_t z = clock();
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case "<<i<<": ";
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}