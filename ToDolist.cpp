#include <bits/stdc++.h>
using namespace std;
//making a class to keep data of the task
class task{
    public:
    string taskname,info;
    int date,month,year;
    task(string name,string tinfo,int _date,int _month, int _year){
        taskname=name;
        info=tinfo;
        date=_date;
        month=_month;
        year=_year;
    }
    //overloading operator to sort the task according to time.
    bool operator <(const task &tsk2)const{
        if(year==tsk2.year){
            if(month==tsk2.month){
                return date<tsk2.date;
            }
            else {
                return month<tsk2.month;
            }
        }
        else {
            return year<tsk2.year;
        }
    }
};
vector<task> tasklist;
void choose_task()
{
    int taskno;
    string chk;
    if(tasklist.size()==0){
        cout<<"Task list is empty!"<<endl;
        return;//We can not show the list as it is empty.
    }
    //Soring the task according to date of task.
    sort(tasklist.begin(),tasklist.end());
    cout<<"To open a task Enter the task number form the list below:"<<endl;
    cout<<"Task No\tTask Name"<<endl;
    //Here we will store everything in vector as 0 based index,but user will see as 1 based index
    //So we have to substruct or add 1 sometimes from index.
    for(int i=0;i<tasklist.size();i++){
        cout<<i+1<<".\t"<<tasklist[i].taskname<<endl;
    }
    cin>>taskno;
    system("clear");//Clear display
    cout<<"Task name: "<<tasklist[taskno-1].taskname<<endl;
    cout<<"Info:\n"<<tasklist[taskno-1].info<<endl;
    cout<<"\nDate: "<<tasklist[taskno-1].date<<"/"<<tasklist[taskno-1].month<<"/"<<tasklist[taskno-1].year<<endl;
    cout<<"\n\nEnter 'm' to go main menu or 'r' to remove this note\n";
    do{
        cin>>chk;
        if(chk=="r"){
            tasklist.erase(tasklist.begin()+taskno-1);
            break;
        }
    }while(chk!="m");
    system("clear");//Clear display
}
void addnewtask()
{
    string inputname,inputinfo;
    int day,month,year;
    //we will input task details here.
    cout<<"Enter task name: ";
    cin>>inputname;
    cout<<"Enter task information: ";
    cin>>inputinfo;
    //getline(cin,inputinfo);//it's not working properly
    cout<<"Enter task date (Format:DD/MM/YYYY): ";
    scanf("%d%*c%d%*c%d",&day,&month,&year);
    //Need to check if input format,added by user is correct. will be done in next update
    if(year<100)year+=2000;//for year 2018 user can input 2018 or only 18. it will be converted here.
    tasklist.push_back(task(inputname,inputinfo,day,month,year));
    system("clear");//Clear display
}
int main()
{
    int i,j,a,b,ts,f=1,cn=0,n;
    int option;
    while(true){
        puts("Chose an option:");
        puts("1.Add a new task\n2.See all task\n3.Exit");
        cin>>option;
        system("clear");//Clear display
        if(option>3||option<1)puts("\nInvalid Option. Try again\n\n");
        //we will use separate function for each option.
        switch(option){
            case 1:
                addnewtask();
                break;
            case 2:
                choose_task();
                break;
            case 3:
                puts("\nThanks for using this program\n");
                return 0;
                break;
        }
    }
    return 0;
}

