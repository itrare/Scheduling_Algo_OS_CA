
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>
#define MAX 1000
COORD coord = {0, 0};
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;
int noProcess,aTs,ttB=0;
struct process{
    int iD,bT,bbT,aT,cT,tAT,wT;

};
process * pArray= new process[MAX];


int x=1,m=1,d;
void madeGanttChar(int id[],int ct[],int z){


int i=0,L=1;
d=0;
ct[0]=0;

for( m =1,x=1;m<=z;m++,x++){

if(m%20==0){

    d+=5;
    x=1;

    gotoxy(x*7,d+2);
}


    gotoxy(x*7,1+d);
    cout<<" ______";
    gotoxy(x*7,1+d);
    cout<<""<<ct[m-1]<<endl;
    gotoxy(x*7,2+d);
    i=m-1;
    cout<<"|  P"<<id[i];
    gotoxy(x*7+7,2+d);
    cout<<"|"<<endl;
    gotoxy(x*7,3+d);
    cout<<"|______|"<<endl;


}

gotoxy(x*7,1+d);
cout<<""<<ct[m-1]<<endl;


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
    gotoxy(0,2);
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
    cin.ignore();
    schedule(noProcess);

    gotoxy(0,8+d-2);
    cout<<"\t+_______________________________________________________________________________________________+";
    gotoxy(8,8+d-1);
    cout<<"|ProcessID \t|BurstTime \t|ArrivalTime\t|CompletionTime\t|TurnAroundTime\t|WaitingTime\t|\n";
    cout<<"\t+_______________________________________________________________________________________________+";
    for(int i=0;i<noProcess;++i){
        gotoxy(8,9+d+i);
        cout<<"|    "<<pArray[i].iD<<"\t\t|    "<<pArray[i].bbT<<"\t\t|    "<<pArray[i].aT<<"\t\t|    "<<pArray[i].cT<<"\t\t|    "<<pArray[i].tAT<<"\t\t|    "<<pArray[i].wT<<"\t\t|"<<endl;

    }
    cout<<"\t+_______________________________________________________________________________________________+\n";

    {

    cout<<"\t\t\t\t+_____________________________________________+\n";
    cout<<"\t\t\t\t|     The Ending time of Pi(i=4) :  "<<pArray[3].cT<<" \t      |"<<endl;
    cout<<"\t\t\t\t+_____________________________________________+\n";
    }


}
/*
Test Case #Original:
5
1 0 10
2 0 29
3 0 3
4 0 7
5 0 12
Test Case #1:
5
1 0 10
2 1 29
3 1 3
4 2 7
5 2 12
Test Case #2:
4
1 0 7
2 2 4
3 4 1
4 5 4

*/
