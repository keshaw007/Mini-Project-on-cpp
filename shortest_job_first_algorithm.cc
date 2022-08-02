#include<bits/stdc++.h>
using namespace std;
class Process_Details
{
public:
    int arrival_time;
    int cpu_burst;
    int io_burst;
    int total_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int completion_time;
    Process_Details()
    {
        arrival_time=-1;
        cpu_burst=-1;
        io_burst=-1;
    }

    int io_burst_calculator(int x, int y);
};


int Process_Details::io_burst_calculator(int x, int y)
{
    if(cpu_burst%y==0)
    {
        return ((cpu_burst/y)-1)*x;
    }
    else
    {
        return (cpu_burst/y)*x;
    }
    return 0;
}


int main()
{
    int system_throughput_time;
    vector<int>arrivalTime;

    // process declaration
    Process_Details p0,p1,p2,p3;

    // 1st process
    p0.arrival_time=0;
    arrivalTime.push_back(p0.arrival_time);
    p0.cpu_burst=24;
    p0.io_burst=p0.io_burst_calculator(2,5);
    p0.total_time=p0.cpu_burst+p0.io_burst;

    // 2nd process
    p1.arrival_time=3;
    arrivalTime.push_back(p1.arrival_time);
    p1.cpu_burst=17;
    p1.io_burst=p1.io_burst_calculator(3,6);
    p1.total_time=p1.cpu_burst+p1.io_burst;
    
    // 3rd process
    p2.arrival_time=8;
    arrivalTime.push_back(p2.arrival_time);
    p2.cpu_burst=50;
    p2.io_burst=1;
    p2.io_burst=p2.io_burst_calculator(2,5);
    p2.total_time=p2.cpu_burst+p2.io_burst;
   
    // 4th process
    p3.arrival_time=15;
    arrivalTime.push_back(p3.arrival_time);
    p3.cpu_burst=10;
    p3.io_burst=1;
    p3.io_burst=p3.io_burst_calculator(3,6);
    p3.total_time=p3.cpu_burst+p3.io_burst;

    sort(arrivalTime.begin(), arrivalTime.end());

    // GANTT Chart
    int i;
    string cpu;
    for(i=0;i<=p0.total_time;i++)
    {
        cpu.push_back('0') ;
    }

    for(;i<=p0.total_time+p3.total_time;i++)
    {
        cpu.push_back('3');
    }
    for(;i<=p0.total_time+p1.total_time+p3.total_time;i++)
    {
        cpu.push_back('1');
    }
    for(;i<=p0.total_time+p1.total_time+p2.total_time+p3.total_time;i++)
    {
        cpu.push_back('2');
    }

    // Response Time
    int j=0;
    for(j=0;j<=cpu.size();j++)
    {
        if(cpu[j]=='0')
        {
            p0.response_time=j;
            break;
        }
    }
    for(j=0;j<=cpu.size();j++)
    {
        if(cpu[j]=='1')
        {
            p1.response_time=j;
            break;
        }
    }
    for(j=0;j<=cpu.size();j++)
    {
        if(cpu[j]=='2')
        {
            p2.response_time=j;
            break;
        }
    }
    for(j=0;j<=cpu.size();j++)
    {
        if(cpu[j]=='3')
        {
            p3.response_time=j;
            break;
        }
    }

    // Completion Time
    int k;
    for(k=cpu.size();k>=0;k--)
    {
        if(cpu[k]=='3')
        {
            p3.completion_time=k;
            break;
        }
    }

    for(k=cpu.size();k>=0;k--)
    {
        if(cpu[k]=='0')
        {
            p0.completion_time=k;
            break;
        }
    }

    for(k=cpu.size();k>=0;k--)
    {
        if(cpu[k]=='1')
        {
            p1.completion_time=k;
            break;
        }
    }

    for(k=cpu.size();k>=0;k--)
    {
        if(cpu[k]=='2')
        {
            p2.completion_time=k;
            break;
        }
    }

    // PRINTING

    cout<<"Above code implementation using Shortest Job First (SJF)\n";

    cout<<"System throughput time is :- "<<(p0.total_time+p1.total_time+p2.total_time+p3.total_time)/4<<"\n";

    // for process p0
    cout<<"\nFor PROCESS P0 :- \n";
    p0.turnaround_time=p0.completion_time-p0.arrival_time;
    p0.waiting_time=p0.turnaround_time-p0.cpu_burst;
    cout<<"Response Time of Process p0 is "<<p0.response_time<<"\n";
    cout<<"Turn Around Time of Process p0 is "<< p0.turnaround_time<<"\n";
    cout<<"Waiting Time of Process p0 is "<< p0.waiting_time<<"\n";

    // for process p1
    cout<<"\nFor PROCESS P1 :- \n";
    p1.turnaround_time=p1.completion_time-p1.arrival_time;
    p1.waiting_time=p1.turnaround_time-p1.cpu_burst;
    cout<<"Response Time of Process p1 is "<<p1.response_time<<"\n";
    cout<<"Turn Around Time of Process p1 is "<< p1.turnaround_time<<"\n";
    cout<<"Waiting Time of Process p1 is "<< p1.waiting_time<<"\n";
    
    // for process p2
    cout<<"\nFor PROCESS P2 :- \n";
    p2.turnaround_time=p2.completion_time-p2.arrival_time;
    p2.waiting_time=p2.turnaround_time-p2.cpu_burst;
    cout<<"Response Time of Process p2 is "<<p2.response_time<<"\n";
    cout<<"Turn Around Time of Process p2 is "<< p2.turnaround_time<<"\n";
    cout<<"Waiting Time of Process p2 is "<< p2.waiting_time<<"\n";

    // for process p3
    cout<<"\nFor PROCESS P3 :- \n";
    p3.turnaround_time=p3.completion_time-p3.arrival_time;
    p3.waiting_time=p3.turnaround_time-p3.cpu_burst;
    cout<<"Response Time of Process p3 is "<<p3.response_time<<"\n";
    cout<<"Turn Around Time of Process p3 is "<< p3.turnaround_time<<"\n";
    cout<<"Waiting Time of Process p3 is "<< p3.waiting_time<<"\n";
    return 0;
}