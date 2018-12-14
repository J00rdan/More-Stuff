#include <iostream>
using namespace std;
#include <fstream>

ifstream fin("data.in");

int n, V[100];
int L[100];
int maxxk = 1;
int k = 1;
int sol[100][100];
int maxx;
int S[100];

int BKTR(int top, int S[], int start){

    if(top == maxx){
        for(int i = 1; i <= maxx; i++) cout << S[i] << " ";
        cout << endl;
    }
    else {
        for(int i = start + 1; i <= n; i++){
            if(V[i] > S[top]){
                S[top + 1] = V[i];
                BKTR(top + 1, S, i);
            }
        }
    }
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> V[i];

    L[n] = 1;

    for(int i = n - 1; i >= 1; i--){
        for(int j = i; j <= n; j++){
            if(V[j] > V[i]){
                if(L[i] < 1 + L[j]) {
                    L[i] = 1 + L[j];
                }
            }
        }
    }

    maxx = L[1];
    int index = 1;

    for(int i = 2; i <= n; i++) {if(L[i] > maxx) maxx = L[i], index = i;}


    cout << maxx << endl;

    for(int i = 1; i <= n; i++) cout << L[i] << " ";
    cout << endl;

    for(int i = 1; i <= n; i++){
        if(L[i] == maxx){
            S[1] = V[i];
            BKTR(1, S, index);
        }
    }

    return 0;
}
