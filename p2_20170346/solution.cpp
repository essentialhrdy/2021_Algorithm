#include <iostream>
#include "p2_solution.h"
using namespace std;
#define MAXNUM 10000

pair<int, int> mergearr[MAXNUM];

void merge(pair<int, int> *list, int l, int m, int r)
{
    int i = l;
    int j = m+1;
    int k = l;

    while (i <= m && j <= r)
    {
        if(list[i].second <= list[j].second)
        {
            mergearr[k] = list[i];
            i++;
        }
        else
        {
            mergearr[k] = list[j];
            j++;
        }
        k++;
    }

    if(i>m)
    {
        for(int t = j; t <=r; t++)
        {
            mergearr[k] = list[t];
            k++;
        }
    }
    else
    {
        for(int t = i; t<= m; t++)
        {
            mergearr[k] = list[t];
            k++;
        }
    }

    for(int t = l; t<=r; t++)
    {
        list[t] = mergearr[t];
    }
}


void merge_sort(pair<int, int> *list, int l, int r)
{
    if(l < r)
    {   
        int m = (l+r)/2;
        merge_sort(list, l, m);
        merge_sort(list, m+1, r);
        merge(list, l, m ,r);
    }
}



int Solution::kMost(std::vector<int> &arr, int len, int k)
{
    pair<int, int> p[MAXNUM];

    for (int i = 0; i < 10000; i++)
    {
        p[i].first = i;
        p[i].second = 0; 
    }

    for(int i = 0; i < len; i++)
    {
        p[arr[i]].second++;        
    }    

    merge_sort(p, 0, 9999);

    int ans = p[MAXNUM-k].first;
    return ans;
}

