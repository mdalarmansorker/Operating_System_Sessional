#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    cout<<"Number of processes: ";
    cin>>p;
    vector<vector<int>>processes;
    // processes[at, bt, p, wt, ct, tat]
    for(int i=0;i<p;i++)
    {
        int at, bt;
        cout<<"P"<<i<<": ";
        cin>>at>>bt;
        vector<int>v;
        v.push_back(at);
        v.push_back(bt);
        v.push_back(i);
        processes.push_back(v);
    }
    sort(processes.begin(),processes.end());
    // add wt
    processes[0].push_back(0);
    // add ct
    processes[0].push_back(processes[0][0]+processes[0][1]);
    //add tat
    processes[0].push_back(processes[0][1]);
    int total_tat = 0;
    int total_wt = 0;
    //ct=bt+wt+at
    int ct=processes[0][1]+processes[0][0];
    for(int i=1;i<p;i++)
    {
        // wt  = wt[i-1]+bt[i-1]
        int wt;
        if(processes[i][0] <= processes[i-1][4])
            wt = processes[i-1][4] - processes[i][0];
        else
            wt = 0;
        processes[i].push_back(wt);
        //ct = bt + at, wt
        ct = processes[i][0]+wt+processes[i][1];
        processes[i].push_back(ct);
        processes[i].push_back((processes[i][4]-processes[i][0]));
    }
    cout<<"P\t"<<"AT\t"<<"WT\t"<<"BT\t"<<"CT\t"<<"TAT"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<processes[i][2]<<"\t"<<processes[i][0]<<"\t"<<processes[i][3]<<"\t"<<processes[i][1]<<"\t"<<processes[i][4]<<"\t"<<processes[i][5]<<endl;
        total_wt += processes[i][3];
        total_tat += processes[i][5];
    }
    double atat = total_tat / double(p);
    double awt = total_wt / double(p);
    cout<<"Average Turn Around Time: "<<atat<<endl;
    cout<<"Average Waiting Time: "<<awt<<endl;
    return 0;
}