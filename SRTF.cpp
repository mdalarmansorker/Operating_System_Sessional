#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arrival_time[20], brust_time[20], temp_brust_time[20];
    int i, smallest, count = 0, time, limit;
    double turn_around_time = 0, ct, average_waiting_time, average_turn_around_time;
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
    for(time = 0; count !=  limit; time++)
    {
        smallest = 19;
        for(i = 0; i<limit;i++)
        {
            if(arrival_time[i]<=time and brust_time[i]<brust_time[smallest] and brust_time[i]>0)
            {
                smallest = i;
            }
        }
        brust_time[smallest]--;
        if(brust_time[smallest]==0)
        {
            count++;
            ct = time +1;
            wait_time = wait_time + ct -  arrival_time[smallest] - temp_brust_time[smallest];
            turn_around_time = turn_around_time + ct - arrival_time[smallest];
        }
    }
    average_turn_around_time = turn_around_time/limit;
    average_waiting_time  = wait_time/limit;
    cout<<"Average waiting time: "<<average_waiting_time<<endl;
    cout<<"Average turn around time: "<<average_turn_around_time<<endl;
    return 0;
}