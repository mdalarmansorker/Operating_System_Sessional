#include<bits/stdc++.h>
using namespace std;
class processes
{
    public:
        int pn, at, bt, ct, wt, tat;

        void show_all()
        {
            cout<<pn<<"\t"<<at<<"\t"<<bt<<"\t"<<ct<<"\t"<<wt<<"\t"<<tat<<endl;
        }
};

int main()
{
    int n;
    cout<<"Number of processes: ";
    cin>>n;
    processes A[n];
    cout<<"AT\tBT"<<endl;
    //input of arrival times and brust times
    for(int i=0; i<n; i++)
    {
        cin>>A[i].at>>A[i].bt;
        A[i].pn = i;
    }
    //insertion sort by the arrival times
    int i, j;
    processes key;
    for(int i=1;i<n;i++)
    {
        key = A[i];
        j = i -1;
        while(j>=0 and A[j].at>key.at)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    //first process's waiting time is zero
    A[0].wt = 0;
    //ct - at = bt + wt = tat
    A[0].ct = A[0].at + A[0].bt + A[0].wt;
    A[0].tat = A[0].wt + A[0].bt;
    int total_wt = A[0].wt, total_tat = A[0].tat;
    int time = A[0].ct;
    for(i=1;i<n;i++)
    {
        if(A[i].at<=time)
        {
            A[i].wt = A[i-1].ct - A[i].at;
        }
        else
        {
            A[i].wt = 0;
        }
        A[i].tat = A[i].wt + A[i].bt;
        A[i].ct = A[i].tat + A[i].at;
        time = A[i].ct;
        total_wt += A[i].wt;
        total_tat += A[i].tat;
    }
    double avg_wt = (double)total_wt/n;
    double avg_tat = (double)total_tat/n;
    cout<<setprecision(2)<<fixed;
    cout<<"Average waiting time: "<<avg_wt<<endl;
    cout<<"Average turn around time: "<<avg_tat<<endl;
    return 0;
}