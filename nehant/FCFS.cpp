#include<iostream>
#include<algorithm>
using namespace std ;
struct process
{
    int pid ;
    int at ;
    int bt ;
    int ct ;
    int tat ;
    int wt ;
};
int main()
{
    int n ;
    cout<<"Enter number of processes : " ;
    cin>>n ;
    process p[n] ;
    for(int i = 0 ; i < n ; i++)
    {
         p[i].pid=i+1 ;
         cout<<"Enter Arrival time for process, Enter Burst time for process" <<p[i].pid<<": ";
         cin>>p[i].at>>p[i].bt;
    }
    sort(p, p + n, [](process a, process b)
         { return a.at < b.at; });

    int time = 0;
    for(int i = 0 ; i < n ; i++)
    {
       if(time<p[i].at)
       {
        time = p[i].at ;
       }
      time = time + p[i].bt ;
      p[i].ct = time ;
      p[i].tat = p[i].ct - p[i].at ;
      p[i].wt = p[i].tat - p[i].bt ;
    }

    cout<<"/PID/AT/BT/CT/TAT/WT/"<<endl ;
    for(int i = 0 ; i<n ; i++)
    {
        cout<<p[i].pid<<"\t";
        cout<<p[i].at<<"\t";
        cout<<p[i].bt<<"\t";
        cout<<p[i].ct<<"\t";
        cout<<p[i].tat<<"\t";
        cout<<p[i].wt<<"\t";
        cout<<endl;
    }
    return 0 ;
}
