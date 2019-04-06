
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>
#define MAX 100
COORD coord = {0, 0};
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;
int noProcess,aTs,ttB=0;
struct process{
    int iD,bT,bbT,aT,cT,tAT,wT;

};
process * pArray= new process[MAX];
int isNullQueue(process *Array[]){


    int isThere=0;
    for(int i=0;i<noProcess;i++){

        if(Array[i]->bT>0){
            isThere=1;

            }

        }


    return isThere;
}
int allDone(){
        int isThere=0;
    for(int i=0;i<noProcess;i++){

        if( pArray[i].bT>0){
            isThere=1;
        }
    }

    return isThere;

}
void madeGanttChar(int id[],int ct[],int z){


int i=0;
ct[0]=0;
int x=1;
int down=3;
for( x =1;x<=z;x++){
if(x*3 >90){
    gotoxy(x*4,down++);
}
    {
        gotoxy(x*4,1);
    cout<<" ___";
    gotoxy(x*4,1);
    cout<<""<<ct[x-1]<<endl;
    gotoxy(x*4,2);
    i=x-1;
    cout<<"|P"<<id[i]<<" |"<<endl;
    gotoxy(x*4,3);
    cout<<"|___|"<<endl;
    }

}

gotoxy(x*4,1);
cout<<""<<ct[x-1]<<endl;


}
void schedule(int noProcess){
    process *ReadyQueue[MAX];
    int length = noProcess;
    int m=0,i=0;
    int id[MAX],ct[MAX];
    int cTValue = 0;

    do{
        cout<<"Executed "<<i+1<<endl;

        if(m<MAX){
            for(int j= 0 ;j<noProcess;j++){
            if(pArray[j].aT==i &&pArray[j].bT>0){
                ReadyQueue[m++] = &pArray[j];
            }
        }
        }
        int minIndex = 0;
        for(int x = 0 ;x<m;x++){
                 if(ReadyQueue[x]->bT>0){

                    minIndex = x;

                 }


        }
       int min=ReadyQueue[minIndex]->bT;

        process *minProcess = *(&ReadyQueue[minIndex]);
        int minPid;
        for(int k=0 ; k<m;k++){
            if(ReadyQueue[k]->bT <= min && ReadyQueue[k]->bT>0){
                minProcess = *(&ReadyQueue[k]);
                minPid = ReadyQueue[k]->iD;
                min = minProcess->bT;
            }


        }
        cout<<minProcess->iD<<endl;

        cTValue++;
        minProcess->cT = cTValue;
        minProcess->bT -=1;
        minProcess->tAT = minProcess->cT - minProcess->aT;
        minProcess->wT = minProcess->tAT - minProcess->bbT;
        system("cls");
    id[i]= minProcess->iD;
    ct[1+i]= minProcess->cT;
    madeGanttChar(id,ct,i+1);
        i++;

        }while(i<ttB );

}
int main(){

    cout<<"How many Process are there: \n";
    cin>>noProcess;
    process *n;
    cout<<"ProcessID \t\tArrivalTime \t\tBurstTime\t\t\n";
    for(int i=0;i<noProcess;++i){
        n = new process;
        cin>>n->iD;
        int bt;
        cin>>n->aT;
        cin>>bt;
        n->bT = bt;
        ttB+=bt;
        n->bbT = bt;

        pArray[i]= (*n);


    }
    schedule(noProcess);
    gotoxy(0,8);
    cout<<"PID \t\tBT \t\tAT\t\tCT\t\tTAT \t\tWT\n";

    for(int i=0;i<noProcess;++i){
        cout<<pArray[i].iD<<"\t\t"<<pArray[i].bbT<<" \t\t"<<pArray[i].aT<<" \t\t"<<pArray[i].cT<<" \t\t"<<pArray[i].tAT<<" \t\t"<<pArray[i].wT<<endl;
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

// sdfsdf sfs


1 0 7
2 2 4
3 4 1
4 5 4
*/
