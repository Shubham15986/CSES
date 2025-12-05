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
  
    string k;cin>>k;
    int  m = k.size();

    vi lps(m,0);
    int i = 1;int j = 0;
    while(i<m){
        if(k[i] == k[j]){
            j+=1;
            lps[i] = j;
            i++;
        }else{
            if(j==0){
                lps[i] =0;
                i++; 
            }
            else{
                j = lps[j-1];
            }
        }
    }
    
     j = m-1;
     int len = lps[m-1];
    vi v;
    while(len>0){
        v.pb(len);
        len = lps[len-1];
        
    }
    int n = v.size();
    rep(i,0,n){
        cout<<v[n-1-i]<<" ";
    }
    
   

	
 
     
}
int32_t main() {
    
   int t;t=1;
   

   while(t--){
    boom();
   }
}