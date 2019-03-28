#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
vector <vector <int> > vec ;
void getProcess(){
    int l;
    cout<<"How many processes are there\n";
    cin>>l;

    for (int j = 0 ; j<l;j++){
        vec.push_back(vector<int>(2));
    }
    for (int n = 0; n < l; n++){        //creating columns for the rows
        for (int m = 0; m <1 ; m++){
            vec[m].push_back(0);
        }
    }
    cout<<"Process No\t\tBurst Time\n";
    for (int x = 0 ;x<l;x++){
        int p,bt;
        cin>>p;
        vec[x][0]=p;
        cin>>bt;
        vec[x][1]=bt;

    }
}

void dis(){
        cout<<"Process No\t\tBurst Time\n";

    for (int j = 0 ;j<vec.size();j++){
        cout<<vec[j][0]<<"\t\t\t"<<vec[j][1]<<endl;
    }

}
//Every Start will make new ways but way is only the one for life.

//sortProcess using count sort
bool sortcol( const vector<int>& v1,const vector<int>& v2 ) {
 return v1[1] < v2[1];
}
void sortProcess(){

int *countArray = new int;
    sort(vec.begin(),vec.end(),sortcol);
}


int main(){

    cout<<"\t\t\t\t SJF NON-PREMPTIVE\n";
    getProcess();
    sortProcess();
    dis();



}
