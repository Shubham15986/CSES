#include<iostream>
#include<algorithm>
  #include <iomanip>
#include <bit>


#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include <numeric>
#include<cstring>

using namespace std;


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
const int mod = 1e9 + 7;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vii vector<pii>
#define in(v,n) rep(i,0,n) cin>>v[i];
#define out(v,n) rep(i,0,n) cout<<v[i]<<" "; cout<<endl;
#define pairout(v,n) rep(i,0,n) cout<<v[i].first<<" "<<cout<<v[i].second<<" "; cout<<endl;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int pow(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result *= a; 
        }
        a *= a;          
        b >>= 1;      
    }
    return result;
}




void boom(){
    int n;cin>>n;
    vi v(n+1,0);
    rep(i,0,n){
        int a;cin>>a;
        v[a]++;
    }
    rep(i,1,n+1){
        if(v[i] == 0){
            cout<<i<<endl;
            break;
        }
    }
	
 
     
}
int32_t main() {
    
   int t;t=1;
   

   while(t--){
    boom();
   }
}