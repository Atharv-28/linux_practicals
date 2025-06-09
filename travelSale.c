#include <stdio.h>
#include <limits.h>
#define V 4
int tsp(int g[V][V],int v[],int pos,int cnt,int cost,int *min){
    if(cnt==V&&g[pos][0])return (*min=(cost+g[pos][0]<*min)?cost+g[pos][0]:*min);
    for(int i=0;i<V;i++)if(!v[i]&&g[pos][i]){v[i]=1;tsp(g,v,i,cnt+1,cost+g[pos][i],min);v[i]=0;}
    return *min;
}
int main(){
    int g[V][V]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}},v[V]={0},min=INT_MAX;
    v[0]=1;printf("Min cost: %d\n",tsp(g,v,0,1,0,&min));
}
