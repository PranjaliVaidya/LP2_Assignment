#include <bits/stdc++.h>
using namespace std;

//structure for holding values
typedef struct Job
{
    int jobNum;
    int deadline;
    int profit;
}Job;

bool compare(Job a, Job b);
void jobSequencing(Job input[], int num);

int main()
{
    int num;
    cin >> num;
    Job input[num];
    // inputing the values
    for (int i = 0; i < num; i++)
    {
        cin >> input[i].jobNum;
        cin >> input[i].profit;
        cin >> input[i].deadline;
    }

    jobSequencing(input, num);
}

// a custom comparison function for arrenging jobs in decreasing order of profit
bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

// main part of code where job sequencing happens
void jobSequencing(Job input[], int num)
{
    sort(input, input + num, compare);

    int result[num];
    
    bool slot[num];
    // setting all values in slot as false
    memset(slot, 0, sizeof(slot));

    for (int i = 0; i < num; i++)
    {
        for (int j = min(num, input[i].deadline)-1; j >= 0; j--)
        {
            if(slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Job sequenced in order: ";
    for (int i=0; i<num; i++)
    {
       if (slot[i] == true)
        cout << input[result[i]].jobNum << " ";
    }
}
// }Enter the number of jobs:5
// 1 100 2
// 2 19 1
// 3 27 2
// 4 25 1
// 5 15 3