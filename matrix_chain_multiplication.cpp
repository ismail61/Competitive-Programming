#include<bits/stdc++.h>
using namespace std;
void printmatrix(int i,int j,int n,int *s,char &name)
{
    /// If only one matrix left in current segment
    if(i==j){
        cout<<name++;
        return;
    }
    cout<<"(";
        /// from i to bracket[i][j].
    printmatrix(i,*((s+i*n)+j),n,s,name);/// *((s+i*n))==s[i][j]
        /// from bracket[i][j] + 1 to j.
    printmatrix(*((s+i*n)+j)+1,j,n,s,name);
    cout<<")";
}
int main(){
    int p[5] = {5, 4, 6, 2, 7};
    int mat[4]={0,1,2,3};
    int n=5,min_,j;
    int m[n][n],s[n][n];
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){///n-d
            j = i+d;
            min_ = 99999;
            for(int k=i;k<j;k++){
                int q = m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<min_){
                    min_ = q;
                    s[i][j]=k;
                }
            }
            m[i][j] = min_;
        }
    }
    char name = 'A';
    printmatrix(1,n-1,n,(int*)s,name);
    cout<<endl;
    printf("%d\n",m[1][n-1]);///raw 1 r last upadan


}
