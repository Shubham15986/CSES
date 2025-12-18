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
#define vvpii vector<vector<pii>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
//const int INF = 1e9;
const int mod = 1e9+7;
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

vi seg;
vi lazy;

void build_st(vi &v,int l,int r,int id){ //id=0;
    if(l==r){
        seg[id]=v[l];
        return;
    }
    int mid = (l+r)/2;
    build_st(v,l,mid,2*id +1);
    build_st(v,mid+1,r,2*id +2);
    seg[id] = min(seg[id*2+1],seg[id*2+2]);
}
int op_st(vi &v,int L,int R,int l,int r,int id){
    if(l<=L && R<=r){
        return seg[id];
    }
    else if( r<L || l>R){
        return 1e18;
    }
    else{
        int mid = (L+R)/2;
        int left = op_st(v,L,mid,l,r,2*id+1);
        int right = op_st(v,mid+1,R,l,r,id*2+2);
        return min(left,right);
    }
}

void lazy_op(vi &v,int L,int R,int l,int r,int id,int val){
    if(lazy[id] != 0){
        seg[id]+= lazy[id]*(R-L+1);
        if(L!=R){
            lazy[2*id+1] += lazy[id];
            lazy[2*id+2] += lazy[id];

        }lazy[id] = 0;

    }
    if(R<l || L>r){
        return;
    }
    if( R<=r && L>=l ){
        if(L!=R){
            lazy[2*id+1] = lazy[id];
            lazy[2*id+2] = lazy[id];
        }
        return;
    }
    int mid = (R+L)>>2;
    lazy_op(v,L,mid,l,r,id,val);
    lazy_op(v,mid+1,R,l,r,id,val);
}
void update_st(int id,int L,int R,int pos,int val){
    if(L==R){
        seg[id] = val;
        return;
    }
    int mid = (L+R)/2;
    if(pos<=mid){
        update_st(2*id+1,L,mid,pos,val);
        
    }else  update_st(2*id+2,mid+1,R,pos,val);

    seg[id] = min(seg[2*id+1],seg[2*id+2]);
}
void boom(){
 int n,m,k;cin>>n>>m>>k;
 vector<vector<pii>> adj(n+1);
 while(m--){
   int a,b,c;cin>>a>>b>>c;
   adj[a].pb({b,c});
 }
 vvi dis(n+1,vi(k,1e18));
 //<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
 priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
 pq.push({0,1,1});
 dis[1][0] = 0;

 while(!pq.empty()){
    
    auto [w,u,v] =  pq.top();pq.pop();
     if(w>dis[v][k-1]) continue;
    for(auto it : adj[v]){
         int nu = it.first;
         int nw = it.second;
         
         int newd = nw+w;
         if( newd<dis[nu][k-1]){
            dis[nu][k-1]=newd;
            sort(all(dis[nu]));
            pq.push({newd,v,nu});
         }
    }
 }
 rep(i,0,k){
    cout<<dis[n][i]<<" ";
 }


}
int32_t main() {
    
   int t; //cin>>t;
  t=1;

   while(t--){
    boom();
   }
}