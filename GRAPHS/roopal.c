#include <stdio.h>

void solve(int lights[], int n,int q)
{
    while(q--){
    int Li, Ri;
    
 
        scanf("%d%d", &Li, &Ri);
        for(int i=Li-1; i<Ri; i++){
            (lights[i]==0)?(lights[i]=1):(lights[i]=0);
        }
 
    }
    for(int i=0;i<n;i++)
     printf("%d ", lights[i]);
}
int main()
{
    int lights[100001];
    int i,n,q;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d", &lights[i]);
    }
    solve(lights,n,q);
    
	return 0;
}