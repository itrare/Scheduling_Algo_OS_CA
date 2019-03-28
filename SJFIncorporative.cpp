#include<iostream>
using namespace std;
void getProcess(int processArray[][]){
    int l;
    cout<<"How many processes are there\n";
    cin>>l;
    cout<<"Process No\t\t Burst Time";
    for (int x = 0 ;x<l;x++){
        int p,bt;
        cin>>p;
        cout<<"\t\t";
        cin>>bt;
        processArray[x][0] = p;
        processArray[x][1] = bt;
    }
}
//Every Start will make new ways but way is only the one for life.
int main(){



}
