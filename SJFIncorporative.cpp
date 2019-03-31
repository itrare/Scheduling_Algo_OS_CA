#include<iostream>
#include<string>
#define MAX 100000

using namespace std;
int noProcess,aTs;
struct process{
    int iD,bT,bbT,aT,cT,tAT,wT;

};
process * pArray= new process[MAX];


void schedule(int noProcess){
    process *ReadyQueue[noProcess];
    int length = noProcess;
    int m=0;
    int cTValue = 0;
    for(int i=0;i<length;i++){

        if(m<length){
        for(int j=0; j<length;j++){
            if(pArray[j].aT==i){
                ReadyQueue[m++] = &pArray[j];
            }

        }

        }
        int minIndex = 0;
        for(int x = 0 ;x<m;x++){
                 if(ReadyQueue[x]->bT>0){
                        //cout<<"x: "<<x;
                    minIndex = x;
                 //cout<<"P"<<ReadyQueue[x]->iD<<" ";
                 }


        }
        int min=ReadyQueue[minIndex]->bT;
        //cout<<"Now considered min is:"<<minIndex<<endl;
        //cout<<endl;
        // finding the min job from the ready queue

        process *minProcess = *(&ReadyQueue[0]);
        int minPid;
        for(int k=0 ; k<m;k++){
            if(ReadyQueue[k]->bT <= min && ReadyQueue[k]->bT>0){
                minProcess = *(&ReadyQueue[k]);
                minPid = ReadyQueue[k]->iD;
                min = minProcess->bT;
            }
            //cout<<"Min Pid will be"<<minProcess->iD<<endl<<endl;

        }

        cTValue+=minProcess->bT;
        minProcess->cT = cTValue;
        minProcess->bT = 0;

        //cout<<"Min Pid"<<minPid<<endl;
        //cout<<endl;

    }

}
int main(){


    cout<<"How many Process are there: \n";
    cin>>noProcess;
    process *n;
    cout<<"Is arrival time same for all process [yes=1/no=0]= ";
    cin>>aTs;
    for(int i=0;i<noProcess;++i){
        n = new process;
        cin>>n->iD;
        int bt;
        cin>>bt;
        n->bT = bt;
        n->bbT = bt;
        if(aTs==1){
            n->aT=0;
        }else{
            cin>>n->aT;
        }
        pArray[i]= (*n);


    }
    schedule(noProcess);
    cout<<"ProcessID \t\tBurstTime \t\tArrivalTime\t\tCompletionTime(endingTime)\n";

    for(int i=0;i<noProcess;++i){
        cout<<pArray[i].iD<<"\t\t\t"<<pArray[i].bbT<<" \t\t\t"<<pArray[i].aT<<" \t\t\t"<<pArray[i].cT<<endl;


    }
    cout<<"The Ending time of Pi(i=4) : "<<pArray[3].cT;

}
/*
// for same arrival time
1 10
2 29
3 3
4 7
5 12

//for different Arrival Time
1 10 0
2 29 1
3 3 1
4 7 2
5 12 2

*/
