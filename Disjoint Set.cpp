#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        rank.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n+1; ++i){
            parent[i]=i;
        }
    }

    void findUPar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUPar(parent[node]);
    } 

    void unionByRank(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(pv);
        if(pu==pv)return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }
        
    }

    void unionBySize(int u, int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
int main(){

}
