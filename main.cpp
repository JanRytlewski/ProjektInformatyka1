#include <iostream>
using namespace std;
int t[7][7];

int main() {
    for (int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            t[i][j] = 0;
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

