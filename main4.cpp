#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void inthe_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

// Question : Given an array and Q queries and in each query, there are 
/*
 
 z[i] - ith position se start hone wali, maximum length of 
        prefix substring
 Two string (P and T) 
 kya P T me hai?
 
 hai i par jayenge T[i, i+P.size()]==p then yes  O(T*P);
 
 O(T+P) 
 8    1    10th se start krenge 
 P + '$' + T
 
 i=P.size()+1
 
 Z[i] = P.size() yes 
 
*/

vector<int>z_algo(string& s){
    int n=s.size();
    int l=0;int r=0;
    vector<int>Z(n);
    Z[0]=n;
    for(int i=1;i<n;i++){
        if(i<=r){
            Z[i]=min(r-i+1,Z[i-l]);
        }
        while(i+Z[i]<n and s[Z[i]]==s[Z[i]+i]){
            Z[i]++;
        }
        if(i+Z[i]-1>r){
            l=i;
            r=i+Z[i]-1;
        }
    }
    return Z;
}

int32_t main(){
    inthe_code();
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    s2+='&';
    s2+=s1;
    vector<int>Z=z_algo(s2);
    int cnt=0;
    for(int i=n;i<=(n+m);i++){
        if(Z[i]==n){
            cnt++;
        }
    }
    cout<<cnt;
}