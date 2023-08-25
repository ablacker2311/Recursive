#include<iostream>
#include<queue>
#include<vector>
bool b[100001];
bool way[1001][1001];
int c[100001];
int bfs(int u,int v,int n){
    std::queue <int> q;
    q.push(u);
    while(!q.empty()){
        int k = q.front();
        for(int i=1;i<=n;i++){
            if(way[k][i] && b[i]){
                c[i] = c[k] + 1;
                b[i] = false;
                q.push(i);
                if(i==v)
                    break;
            }
        }
        q.pop();
    }
    return c[v];
}

int func(int n,std::vector<std::vector<int>> e,int u,int v){
    for(int i=0;i<=n;i++){
        b[i] = true;
        c[i] = 0;
    }

    for(int i=0;i<=n;i++){
        for(int j=1;i<=n;i++){
            way[e[i][0]][e[i][1]] = true;
            way[e[i][1]][e[i][0]] = true;
        }
    }

    int k = bfs(u,v,n);
    return k;
}

int main(){
    int n;
    std::cin>>n;
    int m;
    std::cin>>m;
    std::vector<std::vector<int>> e(m);
    for(int i=0;i<e.size();i++){
        int k,h;
        std::cin>>k>>h;
        e[i] = {k,h};
    }

    int u,v;
    std::cin>>u>>v;
    int k = func(n,e,u,v);
    if(k!=0)
        std::cout<<k;
    else std::cout<<-1;
}