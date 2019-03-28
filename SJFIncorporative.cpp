#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
vector <vector <int> > vec ;
void getProcess(){
    int l,c=0;
    char at;
    cout<<"How many processes are there\n";
    cin>>l;
    cout<<"Is Arrival Time same for all process (y/n)";
    cin>>at;
    if(at=='y')
        c=1;
    for (int j = 0 ; j<l;j++){
        vec.push_back(vector<int>(2));
    }
    for (int n = 0; n < l; n++){        //creating columns for the rows
        for (int m = 0; m <1+c; m++){
            vec[m].push_back(0);
        }
    }
    cout<<"Process No\t\tBurst Time";
    if(at=='n')
        cout<<"\t\tArrival Time\n";
    else
        cout<<endl;

    for (int x = 0 ;x<l;x++){
        int p,bt;
        cin>>p;
        vec[x][0]=p;
        cin>>bt;
        vec[x][1]=bt;
        if(at=='n')
            cin>>vec[x][2];
        else
            vec[x][2]=0;
    }
}

void dis(){
        cout<<"Process No\t\tBurst Time\n";

    for (int j = 0 ;j<vec.size();j++){
        cout<<vec[j][0]<<"\t\t\t"<<vec[j][1]<<endl;
    }

}
//Every Start will make new ways but way is only the one for life.

//sortProcess
bool sortcolAt( const vector<int>& v1,const vector<int>& v2 ) {
 return v1[2] < v2[2];
}
bool sortcolBt( const vector<int>& v1,const vector<int>& v2 ) {
 return v1[1] < v2[1];
}
void sortProcess(){sort(vec.begin(),vec.end(),sortcolAt);}
int sumBt(){
int ls = vec.size();
int sum=0;
while(ls<-1){
    sum+= vec[ls][1];
    ls--;
}
}
void schedule(){

    vector <vector <int> > ganttVector;
    vector <int> readyQueue;
    int initTime = vec[0][2];
    int lastBt = sumBt();
    for(int i=initTime;i<lastBt;i++){
            int m=0;
            while(vec[m][2]==i){
                readyQueue.push_back(vec[m]);
                m++;
            }
            sort(readyQueue.begin(),readyQueue.end(),sortcolBt);
    }

}

int main(){

    cout<<"\t\t\t\t SJF NON-PREMPTIVE\n";
    getProcess();
    sortProcess();
    dis();



}
