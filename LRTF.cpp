// LRTF.cpp
/*
Three students (a, b, c) are arriving in the mess at the same time. The id numbers of
these students are 2132, 2102, 2453 and the food taken time from the mess table is 2, 4 and 8
minutes. If the two students have same remaining time so it is broken by giving priority to the
students with the lowest id number. Consider the longest remaining time first (LRTF) scheduling
algorithm and calculate the average turnaround time and waiting time.
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <windows.h>
#define MAX 500
COORD coord = {0, 0};
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


using namespace std;
int cc;
struct process{
 int PID,at,bt,btt,wt,ct,tat,PR;
};

process *ProcessQueue = new process[MAX];

int sizeBTQueue(process *Array[]){

    int isThere=0;
    for(int i=0;i<cc;i++){
        if(Array[i]->bt>0){
            isThere+=1;
        }
    }

    return isThere;
}
int isNullQueue(process *Array[]){

    int isThere=0;
    for(int i=0;i<cc;i++){

        if(Array[i]->bt>0){
            isThere=1;
        }
    }

    return isThere;
}
int allDone(){
        int isThere=0;
    for(int i=0;i<cc;i++){

        if(ProcessQueue[i].bt>0){
            isThere+=ProcessQueue[i].bt;
        }
    }

    return isThere;

}
int x=1,m=1,d;
void madeGanttChar(int id[],int ct[],int z){


int i=0;
d=0;
ct[0]=0;

for( m =1,x=1;m<=z;m++,x++){

if(m%15==0){

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
    cout<<"|P"<<id[i];
    gotoxy(x*7+7,2+d);
    cout<<"|"<<endl;
    gotoxy(x*7,3+d);
    cout<<"|______|"<<endl;


}

gotoxy(x*7,1+d);
cout<<""<<ct[m-1]<<endl;


}
process &priorityScheduling(process *longAssump, process *CompV){

 if(longAssump->PID < CompV->PID){
    return *longAssump;
 }
 else{
    return *CompV;
 }
 return *longAssump;

}
void lRTFScheduling(){
    process *ReadyQueue[MAX];
    int m=0,i=0,ctGlobal=0;
    int id[MAX],ct[MAX];
    do{

        if(m<cc){
            for(int j= 0 ;j<cc;j++){
            if(ProcessQueue[j].at==i &&ProcessQueue[j].bt>0){
                ReadyQueue[m++] = &ProcessQueue[j];
            }
        }
        }
        process *longRProc = *(&ReadyQueue[0]);

        for(int k= 0 ;k<m;k++){
            if(longRProc->bt < ReadyQueue[k]->bt && ReadyQueue[k]->bt>0){
                longRProc = *(&ReadyQueue[k]);
            }else if(longRProc->bt == ReadyQueue[k]->bt && ReadyQueue[k]->bt>0 ){
                longRProc = (&priorityScheduling(longRProc,ReadyQueue[k]));
            }
            if(ReadyQueue[k]->bt<0){
                delete ReadyQueue[k];
            }
        }
        ctGlobal++;
        longRProc->bt-=1;
        longRProc->ct=ctGlobal;
        longRProc->tat = longRProc->ct - longRProc->at;
        longRProc->wt = longRProc->tat - longRProc->btt;

        cout<<"Long ID:"<<longRProc->PID<<"Long Prcs bt:- and ct:-"<<longRProc->bt<<" " <<longRProc->ct<<endl;


    system("cls");
    id[i]=longRProc->PID;
    ct[1+i]=longRProc->ct;
    madeGanttChar(id,ct,i+1);
        i++;
    }while( i<allDone()||isNullQueue(ReadyQueue)==1 );

}

void getStudents(){
    cout<<"How many student are coming to the mess"<<endl;
    cin>>cc;
    cout<<"PID\t\t ARRIVAL TIME\t\t FOOD TAKEN"<<endl;
    for(int i = 0 ; i<cc;i++){
        cin>>ProcessQueue[i].PID;
        cin>>ProcessQueue[i].at;
        cin>>ProcessQueue[i].bt;
        ProcessQueue[i].btt= ProcessQueue[i].bt;
        cout<<endl;
    }
}
void display(){
    cout<<"\tPROCESS ID\t ARRIVAL TIME\t BURST TIME\t COMPLETION TIME  TAT\t\t WT"<<endl;
    float avgWt=0,avgTAT=0;
    for(int i =0 ;i<cc;i++){
        cout<<"\t"<<ProcessQueue[i].PID<<"\t\t "<<ProcessQueue[i].at<<"\t\t "<<ProcessQueue[i].btt<<"\t\t "<<ProcessQueue[i].ct<<"\t\t  "<<ProcessQueue[i].tat<<"\t\t "<<ProcessQueue[i].wt<<endl;
        avgTAT+=ProcessQueue[i].tat;
        avgWt+=ProcessQueue[i].wt;
    }
    cout<<"\tAverage TAT "<<(float)avgTAT/cc<<endl;
    cout<<"\tAverage WT  "<<(float)avgWt/cc<<endl;

}
int main(){
    getStudents();
    lRTFScheduling();
    gotoxy(0,8+d);
    display();

}

/*
Test Case #Original:
3
2132 0 2
2102 0 4
2453 0 8

Test Case #1:
3
2132 0 2
2102 2 4
2453 4 8

Test Case #2:
3
1 4 32
2 5 57
3 5 47

Test Case #3:
4
1 1 2
2 2 4
3 3 6
4 4 8

Test Case #4:
5
1 0 2
2 0 3
3 2 2
4 3 5
5 4 4
*/
