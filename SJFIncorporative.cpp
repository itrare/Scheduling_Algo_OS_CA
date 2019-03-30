#include<iostream>
#include<string>
#define MAX 100000

using namespace std;

struct process{
    int iD;
    int bT;
    int aT;
    int cT;
    int tAT;
    int wT;

};
class Schedule{
   private :process m[MAX];
   Schedule(process n){

   }
   void displayTable(){

   }



};
int main(){

    int noProcess,aTs;

    cout<<"How many Process are there: \n";
    cin>>noProcess;
    process *n;
    process * pArray[noProcess];
    cout<<"Is arrival time same for all process [yes=1/no=0]= ";
    cin>>aTs;
    for(int i=0;i<noProcess;++i){
        n = new process;
        cin>>n->iD;
        cin>>n->bT;
        if(aTs==1){
            n->aT=0;
        }else{
            cin>>n->aT;
        }
        pArray[i]= n;


    }
    cout<<"ID \t\tBT \t\tAT\n";

    for(int i=0;i<noProcess;++i){
        cout<<pArray[i]->iD<<"\t\t"<<pArray[i]->bT<<" \t\t"<<pArray[i]->aT<<endl;


    }
    //Schedule doSchedule = new Schedule(pArray);




}
