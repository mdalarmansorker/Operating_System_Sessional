#include <bits/stdc++.h>
using namespace std;

class process 
{
    public:
        int arrival_time, burst_time, burst_remaining, completion_time, turnaround_time, waiting_time;
};
bool compare(process p1, process p2) {return p1.arrival_time < p2.arrival_time;}

int main() 
{
    int n, tq;
    process p[100];
    int total_turnaround_time = 0, total_waiting_time = 0;
    int idx;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter time quantum: ";
    cin>>tq;
    for(int i = 0; i < n; i++) 
    {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].burst_remaining = p[i].burst_time;
    }
    sort(p,p+n,compare);       //sorting by arrival time
    queue<int>q;                //ready queue
    int current_time = 0;       
    q.push(0);
    int completed = 0;          //how many process is completed yet
    int mark[100];              //process is runned for once or not
    memset(mark,0,sizeof(mark));    //copy 0 to mark[0-99]
    mark[0] = 1;
    while(completed != n) 
    {
        idx = q.front();
        q.pop();
        if(p[idx].burst_remaining == p[idx].burst_time) 
        {
            current_time = max(current_time,p[idx].arrival_time);
        }
        if(p[idx].burst_remaining-tq > 0) 
        {
            p[idx].burst_remaining -= tq;
            current_time += tq;
        }
        else 
        {
            current_time += p[idx].burst_remaining;
            p[idx].burst_remaining = 0;
            completed++;        //as this process is completed
            p[idx].completion_time = current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
        }
        for(int i = 1; i < n; i++) {
            if(p[i].burst_remaining > 0 && p[i].arrival_time <= current_time && mark[i] == 0) 
            {
                q.push(i); //pushing to ready queue
                mark[i] = 1;
            }
        }
        if(p[idx].burst_remaining > 0) {
            q.push(idx);
        }
        if(q.empty()) 
        {
            for(int i = 1; i < n; i++) 
            {
                if(p[i].burst_remaining > 0) 
                {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }
    cout<<setprecision(2)<<fixed;
    cout<<"Average Turnaround Time = "<<(float) total_turnaround_time / n<<endl;
    cout<<"Average Waiting Time = "<<(float) total_waiting_time / n<<endl;
    return 0;
}