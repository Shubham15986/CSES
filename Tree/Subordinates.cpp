#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <numeric>
#include <functional>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#if defined(__GNUG__) && !defined(__clang__)
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;

    template <class T>
    using ordered_set = tree<
        T,
        null_type,
        std::less<T>,
        rb_tree_tag,
        tree_order_statistics_node_update
    >;

#else
    // ===== PBDS FALLBACK (VS Code / non-GNU) =====
    template <class T>
    class ordered_set {
    private:
        std::set<T> s;

    public:
        using iterator = typename set<T>::iterator;
        using const_iterator = typename set<T>::const_iterator;
        void insert(const T& x) {
            s.insert(x);
        }
        void erase(const T& x) {
            s.erase(x);
        }
        void erase(iterator it) {
            s.erase(it);
        }
        iterator find(const T& x) {
            return s.find(x);
        }
        int size() const {
            return (int)s.size();
        }
        bool empty() const {
            return s.empty();
        }
        iterator begin() {
            return s.begin();
        }

        iterator end() {
            return s.end();
        }

        // k-th smallest element (0-indexed)
        iterator find_by_order(int k) {
            auto it = s.begin();
            advance(it, k);
            return it;
        }
        // count of elements strictly less than x
        int order_of_key(const T& x) {
            return distance(s.begin(), s.lower_bound(x));
        }
    };
#endif


#define int long long  
             
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()


#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define each(x, a) for (auto &x : a)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
const int INF = 1e18;
const int mod = 1e9+7;
// find by size
struct DSU {
    vi par,siz;

    DSU(int n) {
        par.resize(n);
        siz.assign(n, 1);
        for (int i = 0; i < n; i++) par[i] = i;
    }


    int findParent(int u) {
        if (par[u] == u) return u;
        return par[u] = findParent(par[u]);
    }


    void unionBySize(int u, int v,int &maxi) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (siz[pu] < siz[pv]) {
            par[pu] = pv;
            siz[pv] += siz[pu];
            maxi = max(maxi, siz[pv]);
        } else {
            par[pv] = pu;
            siz[pu] += siz[pv];
            maxi = max(maxi, siz[pu]);
        }
    }
};
struct SegTree{
    int n;
    vi seg, lazy;

    SegTree(int n) {
        this->n = n;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Build segment tree from array v
    void build(vi &v, int id, int l, int r) {
        if(l==r){
            seg[id] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(v, 2 * id + 1, l, mid);
        build(v, 2 * id + 2, mid + 1, r);
        seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
    }
    // Push lazy value to children
    void push(int id, int l, int r) {
        if (lazy[id] != 0) {
            seg[id] += lazy[id] * (r - l + 1); 

            if (l != r) { 
                lazy[2 * id + 1] += lazy[id];
                lazy[2 * id + 2] += lazy[id];
            }
            lazy[id] = 0; 
        }
    }

    // Range update: add val to range [ql, qr]
    void rangeUpdate(int id, int l, int r, int ql, int qr, int val) {
        push(id, l, r);

        if (r < ql || l > qr) return; // no overlap

        if (l >= ql && r <= qr) { //complete overlap
            lazy[id] += val;
            push(id, l, r);
            return;
        }
        int mid = (l+r)/2;
        rangeUpdate(2 * id + 1, l, mid, ql, qr, val);
        rangeUpdate(2 * id + 2, mid + 1, r, ql, qr, val);
        seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
    }

    // Range sum query [ql, qr]
    long long query(int id, int l, int r, int ql, int qr) {
        push(id, l, r);

        if (r < ql || l>qr) return 0; // no overlap
        if (l >= ql && r <= qr) return seg[id]; // complete overlap

        int mid = (l + r) / 2;
        return query(2 * id + 1, l, mid, ql, qr)
             + query(2 * id + 2, mid + 1, r, ql, qr);
    }

    // Point update: set position pos to val
    void pointUpdate(int id, int l, int r, int pos, int val) {
        push(id, l, r);

        if (l == r) {
            seg[id] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
            pointUpdate(2 * id + 1, l, mid, pos, val);
        else
            pointUpdate(2 * id + 2, mid + 1, r, pos, val);

        seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
    }
};
vi spf;

void sieveSPF(int n) {
    spf.resize(n + 1);
    for (int i = 1; i <= n; i++) spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
vi primeFactors(int x) { // returns 84: 2,2,3,7
    vi factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}
map<int,int> primeFactorCount(int x) {// returns 84 : 2^2 , 3^1, 7^1
    map<int,int> mp;
    while (x > 1) {
        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int powe(int a,int b,int mod){
    int mul = 1;
    while(b>0){
        if(b&1) mul = (((mul)%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b/=2;
    }
    return mul%mod;
}
void dfs(int node,vi &vis, vvi &adj, stack<int> &st){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs2(int node,vi &vis, vvi &adjN, vi &ans, int k){
    vis[node]=1;
    ans[node]=k;
    for(auto it: adjN[node]){
        if(!vis[it]){
            dfs2(it,vis,adjN,ans,k);
        }
    }
 
}

void dfs(int node, vvi &tree, vi &cnt){
    int cou =0;
 //  vis[node]=1;
   for(auto it: tree[node]){
     dfs(it,tree,cnt);
     cou +=  cnt[it] + 1;
        

   }
   cnt[node]=cou;

}


void boom(){
    int n;cin>>n;
    vi v(n);
    vvi tree(n+1);
    rep(i,2,n+1){
      int a;cin>>a;
      tree[a].pb(i);
    }
  //  vi vis(n+1,0);
    vi cnt(n+1,0);
    dfs(1,tree,cnt);
    rep(i,1,n+1){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    
}

int32_t main() {
    
   int t; //cin>>t;
   t=1;

   while(t--){
    boom();
   }
}