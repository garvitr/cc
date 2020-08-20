#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define MOD1 1000000007
#define MOD2 1000000009
#define pb push_back
#define fi first
#define se second
#define sortv(a) sort(a.begin(),a.end())
#define sorta(a,n) sort(a,a+n)
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define maxv(v) *max_element(v.begin(),v.end())
#define minv(v) *min_element(v.begin(),v.end())
#define all(vec) vec.begin(),vec.end()
#define rall(vec) vec.rbegin(),vec.rend()
#define sz(r) r.size()
#define zero(a) memset(a, 0, sizeof(a));
#define sum(v) accumulate(v.begin(),v.end(),0)
#define remi(v, i) (v.erase(v.begin()+i))
#define for0(i, n) for (ll i = 0; i < (ll)(n); ++i) // 0 based indexing
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (ll i = (ll)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (ll i = (ll)(n); i >= 1; --i) // reverse 1 based
// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())
//DEBUG
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";

const int MX = 1e5 + 5;

vector <ll> g[MX];
vector <ll> v(MX);
bool vis[MX];

//Convert String to vector of INT
template <typename T>
vl to_int(T num)
{
	vl val;
	for0(i, num.size()) {
		val.pb(num.at(i) - '0');
	}
	return val;
}

//Reads graph for n nodes;
template <typename T>
void read_graph(T num)
{
	for1(i, num) {
		ll u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	return;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vl v = to_int(s);
		for0(i, v.size()) {
			cout << v[i] << " ";
		}
		// cin >> s;
		// cout << to_int(s);
		// cout << ans << endl;
	}


}