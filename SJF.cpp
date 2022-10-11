#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arrival_time[20], brust_time[20], temp_brust_time[20], completion_time[20];
    int i, smallest, count = 0, time, limit;
    double  wait_time = 0, turn_around_time = 0; 
    double average_waiting_time, average_turn_around_time;
    cout<<"Number of process: ";
    cin>>limit;
    cout<<"Enter details of "<<limit<<" process: "<<endl;
    for(i=0;i<limit;i++)
    {
        cout<<"AT\tBT"<<endl;
        cin>>arrival_time[i]>>brust_time[i];
        temp_brust_time[i]=brust_time[i];
    }
    brust_time[19] = 99999;
    time = 0;
    
    while(count < limit)
    {
        smallest = 19;
        bool checked = false;
        for(i = 0; i<limit;i++)
        {
            if(arrival_time[i]<=time and brust_time[i]<brust_time[smallest] and brust_time[i]>0)
            {
                smallest = i;
                checked = true;
            }
        }
        if(!checked)
        {
            time++;
            continue;
        }
        time += brust_time[smallest];
        completion_time[smallest] = time;
        brust_time[smallest]=0;
        count++;
        wait_time = wait_time + completion_time[smallest]-arrival_time[smallest]-temp_brust_time[smallest];
        turn_around_time = turn_around_time + completion_time[smallest]-arrival_time[smallest];
    }
    average_turn_around_time = turn_around_time/limit;
    average_waiting_time  = wait_time/limit;
    cout<<"Average waiting time: "<<average_waiting_time<<endl;
    cout<<"Average turn around time: "<<average_turn_around_time<<endl;
    return 0;
}