#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int t[6][7];
int n;
int main() {
    cin>>n;
    t[5][n-1]=1;

    for (int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
            if(t[i][j]==0){
            cout<<t[i][j]<<" ";}
            if(t[i][j]>0){
            cout<<t[i][j]<<" ";
            }
        }
        cout<<endl;

    }






    return 0;
}


